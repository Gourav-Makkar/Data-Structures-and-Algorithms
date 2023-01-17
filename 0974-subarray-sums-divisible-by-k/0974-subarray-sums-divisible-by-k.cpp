class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        unordered_map<int,int>m;
        
        int cs=0,i=0;
        while(i<n)
        {
            cs+=nums[i];
            int mod=cs%k;
            if(mod<0)
                mod+=k;
            if(mod==0)
                ans++;
            if(m.find(mod)!=m.end())
                ans+=m[mod];
            m[mod]++;
            i++;
        }
        return ans;
    }
};