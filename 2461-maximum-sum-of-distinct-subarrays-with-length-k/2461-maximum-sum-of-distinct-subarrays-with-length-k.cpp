class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int>m;
        int i=0,j=0;
        long long cs=0;
        while(j<n)
        {
            cs+=nums[j];
            m[nums[j]]++;
            if(j-i+1==k && m.size()==j-i+1)
            {
                ans=max(ans,cs);
            }
            else if(j-i+1>k)
            {
                while(j-i+1>k)
                {
                    cs-=nums[i];
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                        m.erase(nums[i]);
                    i++;
                }
                if(m.size()==j-i+1)
                    ans=max(ans,cs);
            }
            j++;
        }
        return ans;
    }
};