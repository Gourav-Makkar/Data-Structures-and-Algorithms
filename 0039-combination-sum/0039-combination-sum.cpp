class Solution {
public:
    
    void helper(int idx,vector<int>&arr,int sum,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(sum==0)
        {
            ans.push_back(curr);
            return;
        }
        if(idx==arr.size())
            return;
        
        if(arr[idx]<=sum)
        {
            curr.push_back(arr[idx]);
            helper(idx,arr,sum-arr[idx],curr,ans);
            curr.pop_back();
        }
        
        helper(idx+1,arr,sum,curr,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        
        vector<int>curr;
        helper(0,candidates,target,curr,ans);
        
        return ans;
    }
};