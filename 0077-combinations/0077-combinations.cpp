class Solution {
public:
    
    void helper(int n,int idx,int k,vector<int>curr,vector<vector<int>>&ans)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<=n;i++)
        {
            curr.push_back(i);
            helper(n,i+1,k,curr,ans);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(n,1,k,curr,ans);
        
        return ans;
    }
};