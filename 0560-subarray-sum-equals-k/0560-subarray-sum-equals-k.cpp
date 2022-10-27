class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans=0;
        int n=nums.size();
        int cs=0;
        for(int i=0;i<n;i++)
        {
            cs+=nums[i];
            if(cs==k)
                ans++;
            if(m.find(cs-k)!=m.end())
                ans+=m[cs-k];
            m[cs]++;
        }
        return ans;
    }
};