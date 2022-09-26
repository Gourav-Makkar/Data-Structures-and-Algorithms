class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=i;
            }
            else
            {
                int idx=m[nums[i]];
                if(abs(i-idx)<=k)
                    return true;
            }
            m[nums[i]]=i;
        }
        return false;
    }
};