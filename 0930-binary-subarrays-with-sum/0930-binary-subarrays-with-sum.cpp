class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int i=0,j=0;
        
        int cs=0;
        int ans=0;
        unordered_map<int,int>m;
        while(j<n)
        {
            cs+=nums[j];
            if(cs==goal)
                ans++;
            if(m.find(cs-goal)!=m.end())
                ans+=m[cs-goal];
            m[cs]++;
            j++;
        }
        return ans;
    }
};