class Solution {
public:
    
    void helper(int idx,vector<int>&nums,vector<int>&curr,int prev,set<vector<int>>&s)
    {
        if(idx==nums.size())
        {
            if(curr.size()>=2)
            {
                s.insert(curr);
            }
            return;
        }
        
        if(nums[idx]>=prev)
        {
            curr.push_back(nums[idx]);
            helper(idx+1,nums,curr,nums[idx],s);
            curr.pop_back();
        }
        helper(idx+1,nums,curr,prev,s);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        set<vector<int>>s;
        helper(0,nums,curr,INT_MIN,s);
        
        for(auto it:s)
            ans.push_back(it);
        
        return ans;
    }
};