class Solution {
public:
    
    void helper(int idx,vector<int>&nums,vector<int>curr,set<vector<int>>&ans)
    {
        if(idx==nums.size())
        {
            ans.insert(curr);
            return;
        }
        helper(idx+1,nums,curr,ans);
        curr.push_back(nums[idx]);
        
        helper(idx+1,nums,curr,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        
        set<vector<int>>temp;
        
        helper(0,nums,curr,temp);
        for(auto it:temp)
            ans.push_back(it);
        return ans;
    }
};