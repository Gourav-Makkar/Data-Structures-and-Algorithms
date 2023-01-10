class Solution {
public:
    
    void helper(int idx,int n,int k,vector<int>curr,vector<vector<int>>&ans)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx;i<=n;i++)
        {
            curr.push_back(i);
            helper(i+1,n,k,curr,ans);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        
        helper(1,n,k,{},ans);
        return ans;
    }
};