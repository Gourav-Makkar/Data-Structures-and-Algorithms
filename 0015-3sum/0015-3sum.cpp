class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        vector<vector<int>>ans;
        
        for(int i=0;i<n-2;i++)
        {
            int st=i+1,en=n-1;
            
            while(st<en)
            {
               int sum=nums[i]+nums[st]+nums[en];
               if(sum==0)
               {
                   s.insert({nums[i],nums[st],nums[en]});
                   st++;
                   en--;
               }
               else if(sum>0)
                   en--;
               else
                    st++;
            }
        }
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};