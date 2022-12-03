class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int cs=0;
        unordered_map<int,int>m;
        
        while(i<n)
        {
            cs+=nums[i];
            if(i>0 && cs%k==0)
                return true;
            int mod=cs%k;
            if(m.find(mod)!=m.end() && i-m[mod]>=2)
                return true;
            
            else if(m.find(mod)==m.end())
                m[mod]=i;
           i++;
        }
        return false;
    }
};