class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        int i=0;
        int cs=0,ans=0;
        while(i<n)
        {
            cs+=nums[i];
            if(cs%k==0)
                ans++;
            int mod=cs%k;
            if(mod<0)
                mod+=k;
            if(m.find(mod)!=m.end())
              ans+=m[mod];
            
            m[mod]++;
            i++;
        }
        return ans;
    }
};