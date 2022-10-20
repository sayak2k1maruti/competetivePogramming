class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                
                int st=j+1;
                int ed=n-1;
                
                while(st<ed)
                {
                    long long sum = (long long)nums[i]+nums[j]+nums[st]+nums[ed];
                    
                    if(sum==target)
                    {
                        
                        ans.push_back({nums[i], nums[j], nums[st],nums[ed]});
                        
                        int prev= nums[st];
                        while(st<ed && nums[st]==prev) st++;
                        prev=nums[ed];
                        while(ed>st && nums[ed]==prev ) ed--;
                    }
                    else if(sum>target)
                        ed--;
                    else
                        st++;
                }
                    
            }
        }
        
        return ans;
    }
};