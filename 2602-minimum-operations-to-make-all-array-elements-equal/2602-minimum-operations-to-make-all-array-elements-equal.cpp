class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>ans,prefix(n+1);
        
        prefix[0]=0;
        for(int i=1;i<=n;i++)
            prefix[i]=prefix[i-1]+nums[i-1];
        
        for(long long it:queries)
        {
            int idx=upper_bound(nums.begin(),nums.end(),it) - nums.begin();
            // cout<<idx<<endl;
            long long ct1=it*(idx) - prefix[idx];
            long long ct2=(prefix[n]-prefix[idx]) - it*(n-idx);
            
            ans.push_back(ct1+ct2);
        }
        return ans;
    }
};