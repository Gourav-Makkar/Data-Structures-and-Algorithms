class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int>m;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int rem=nums[i]%space;
            m[rem]++;
            if(m[rem]>mx)
                mx=m[rem];
        }
        int ans=INT_MAX;
        for(auto x:nums)
        {
            if(m[x%space]==mx)
                ans=min(ans,x);
        }
        return ans;
    }
};