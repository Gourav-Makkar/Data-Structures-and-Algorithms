class Solution {
public:
    
    int helper(string s1,string s2,int idx1,int idx2,vector<vector<int>>&dp)
    {
        if(idx1==0)
            return idx2;
        if(idx2==0)
            return idx1;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(s1[idx1-1]==s2[idx2-1])
           return helper(s1,s2,idx1-1,idx2-1,dp);
        
        int ins=1 + helper(s1,s2,idx1,idx2-1,dp);
        int del=1 + helper(s1,s2,idx1-1,idx2,dp);
        int rep=1+ helper(s1,s2,idx1-1,idx2-1,dp);
        
        return dp[idx1][idx2]=min(ins,min(del,rep));
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return helper(word1,word2,n,m,dp);
        
    }
};