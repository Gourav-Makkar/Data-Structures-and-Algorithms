class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int i=0,j=0;
        int cs=0;
        
        unordered_map<int,int>m;
        
        while(j<n)
        {
            cs+=nums[j];
            if(cs==k)
                ans++;
            if(m.find(cs-k)!=m.end())
            {
                ans+=m[cs-k];
            }
            m[cs]++;
            j++;
        }
        return ans;
    }
};