class Solution {
public:
    vector<vector<int>> generate(int numRows) {
vector<vector<int>>ans;
vector<int>temp;
temp.push_back(1);
ans.push_back(temp);
int i=2;
while(i<=numRows)
{
    vector<int>x(i , 1);
    for(int j=1 ; j<x.size()-1  ; j++)
    {
        x[j]=temp[j]+temp[j-1];
    }
    ans.push_back(x);
    temp=x;
    i++;
}
        
return ans;
    }
};