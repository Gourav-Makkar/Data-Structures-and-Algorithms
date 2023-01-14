class Solution {
public:
    
    void helper(int idx,vector<int>nums,set<vector<int>>&s)
    {
        if(idx==nums.size())
        {
            s.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            helper(idx+1,nums,s);
            swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        
        helper(0,nums,s);
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};