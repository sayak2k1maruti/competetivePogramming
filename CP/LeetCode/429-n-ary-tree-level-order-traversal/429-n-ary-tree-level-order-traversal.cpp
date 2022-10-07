class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
vector<vector<int>>ans;
if(root==NULL) return ans;
queue<Node*>q;
q.push(root);
while(q.size())
{
    int n=q.size();
    vector<int>temp;
    while(n--)
    {
        auto current=q.front();
        q.pop();
        for(auto i : current->children)
        {
            if(i) q.push(i);
        }
        temp.push_back(current->val);
    }
    ans.push_back(temp);
}
        return ans;
    }
};