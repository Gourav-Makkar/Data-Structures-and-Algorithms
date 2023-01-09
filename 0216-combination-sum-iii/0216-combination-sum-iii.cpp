class Solution {
public:
    
    void helper(int v,int k,int sum,vector<int>curr,vector<vector<int>>&ans)
    {
        if(curr.size()>k)
            return;
        
        if(curr.size()==k && sum==0)
        {
            ans.push_back(curr);
            return;
        }
        if(v>9)
            return;
        if(v<=sum)
        {
            curr.push_back(v);
            helper(v+1,k,sum-v,curr,ans);
            curr.pop_back();
        }
        helper(v+1,k,sum,curr,ans);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>curr;
        
        helper(1,k,n,curr,ans);
        return ans;
    }
};