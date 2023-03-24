class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        
        int i=0,j=0;
        long long cs=0,ans=INT_MIN;
        while(j<n)
        {
            m[nums[j]]++;
            cs+=nums[j];
            
            if(j-i+1==k)
            {
                if(m.size()==k)
                  ans=max(ans,cs);
                m[nums[i]]--;
                
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                
                cs-=nums[i];
                i++;
            }
            j++;
        }
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
};