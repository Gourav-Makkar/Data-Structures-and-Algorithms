class Solution {
public:
    
    int helper(int idx1,int idx2,string &s,vector<vector<int>>&dp)
    {
        if(idx1>idx2)
            return 0;
        
        if(idx1==idx2)
            return 1;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(s[idx1]==s[idx2])
            return dp[idx1][idx2]=2+helper(idx1+1,idx2-1,s,dp);
        
        return dp[idx1][idx2]=max(helper(idx1+1,idx2,s,dp),helper(idx1,idx2-1,s,dp));
    }
    
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ct=helper(0,n-1,s,dp);
        
        return n-ct;
    }
};