class Solution {
public:
    
    int helper(int idx1,int idx2,string &s,string &t,vector<vector<int>>&dp)
    {
        if(idx2<0)
          return 1;
        
        if(idx1<0)
          return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        int ans=0;
        
        if(s[idx1]==t[idx2])
            ans+=helper(idx1-1,idx2-1,s,t,dp);
        
        ans+=helper(idx1-1,idx2,s,t,dp);
        
        return dp[idx1][idx2]=ans;
    }
    
    int numDistinct(string s, string t) {
        int n1=s.size(),n2=t.size();
        
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        
        return helper(n1-1,n2-1,s,t,dp);
    }
};