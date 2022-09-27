class Solution {
public:
     
    void helper(vector<int>ip,vector<int>op,int idx,int target,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<ip.size();i++)
        {
            if(i>idx && ip[i]==ip[i-1])
                continue;
            if(ip[i]<=target)
            {
                op.push_back(ip[i]);
                helper(ip,op,i+1,target-ip[i],ans);
                op.pop_back();
            }
            else if(ip[i]>target)
                break;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        sort(candidates.begin(),candidates.end());
        helper(candidates,op,0,target,ans);
        return ans;
    }
};