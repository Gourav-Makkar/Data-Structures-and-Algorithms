class Solution {
public:
    
    int helper(vector<int>&nums,int k)
    {
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        
        unordered_map<int,int>m;
        
        while(j<n)
        {
            m[nums[j]]++;
            while(m.size()>k)
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return helper(nums,k)-helper(nums,k-1);
    }
};