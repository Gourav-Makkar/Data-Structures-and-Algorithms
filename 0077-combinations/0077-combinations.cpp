class Solution {
public:
    
    void helper(int idx,int n,int k,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }
        
        if(idx>n)
            return;
        
        helper(idx+1,n,k,curr,ans);
        
        curr.push_back(idx);
        helper(idx+1,n,k,curr,ans);
        curr.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(1,n,k,curr,ans);
        return ans;
    }
};