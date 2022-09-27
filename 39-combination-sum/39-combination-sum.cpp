class Solution {
public:
    
    void helper(vector<int>ip,vector<int>op,int cs,int idx,int target,vector<vector<int>>&ans)
    {
        if(cs>target)
            return;
        if(cs==target)
        {
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<ip.size();i++)
        {
            cs+=ip[i];
            op.push_back(ip[i]);
            helper(ip,op,cs,i,target,ans);
            
            cs-=ip[i];
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        vector<vector<int>>ans;
        helper(candidates,op,0,0,target,ans);
        
        return ans;
    }
};