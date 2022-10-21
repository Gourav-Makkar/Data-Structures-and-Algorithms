class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        bool ans=false;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=i;
            }
            else
            {
                if(abs(i-m[nums[i]])<=k)
                   ans=true;
                m[nums[i]]=i;
            }
        }
        return ans;
    }
};