class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        int i=0,cs=0,ans=0;
        
        while(i<n)
        {
            cs+=nums[i];
            if(cs==k)
                ans++;
            if(m.find(cs-k)!=m.end())
                ans+=m[cs-k];
            m[cs]++;
            i++;
        }
        return ans;
    }
};