class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
vector<vector<pair<int , int>>>ans;
queue<pair<TreeNode* , int> >q;
q.push({root , 0});
int a , b;
int x , y;
while(q.size())
{
    int n=q.size();
    vector<pair<int , int>>temp;
    for(int i=0 ; i<n ; i++)
    {
        auto current=q.front();
        q.pop();
        auto c=current.first;
        y=current.second;
         a=min(a , y);
        b=max(b , y);
        if(c->left)q.push({c->left , y-1 });
        if(c->right)q.push({c->right,  y+1});
        temp.push_back({c->val , y});
    }
    x++;
    sort(temp.begin() , temp.end());
    ans.push_back(temp);
}
unordered_map<int , vector<int>>m;
a=INT_MAX;
b=INT_MIN;
vector<vector<int>>ans1;
for(auto i  : ans)
{
    for(auto j : i )
    {
        m[j.second].push_back(j.first);
        a=min(a , j.second);
        b=max(b , j.second);
    }
}
cout<<a<<" "<<b;
for(int i=a ; i<=b ; i++)
{
    vector<int>temp=m[i];
    ans1.push_back(temp);
}
return ans1;
    }
};