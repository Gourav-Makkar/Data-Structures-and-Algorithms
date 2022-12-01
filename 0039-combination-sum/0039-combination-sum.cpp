class Solution {
public:
    
    void helper(vector<int>&v,int idx,int target,vector<int>curr,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(curr);
            return;
        }
        if(idx==v.size())
            return;
        
        bool flag=false;
        if(v[idx]<=target)
        {
            flag=true;
            curr.push_back(v[idx]);
            helper(v,idx,target-v[idx],curr,ans);
        }
        if(flag)
            curr.pop_back();
        helper(v,idx+1,target,curr,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        
        vector<int>curr;
        int n=candidates.size();
        
        helper(candidates,0,target,curr,ans);
        return ans;
    }
};