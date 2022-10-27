class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cs=0;
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
        {
            cs+=nums[i];
            int mod=cs%k;
            if(mod==0 && i>=1)
                return true;
            if(m.find(mod)!=m.end() && i-m[mod]>=2)
              return true;
            else if(m.find(mod)==m.end())
                m[mod]=i;
        }
        return false;
    }
};