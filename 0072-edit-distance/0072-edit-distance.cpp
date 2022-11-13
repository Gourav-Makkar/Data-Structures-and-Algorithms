class Solution {
public:
    
    int helper(string s1,string s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i-1]==s2[j-1])
            return dp[i][j] = 0 + helper(s1,s2,i-1,j-1,dp);
        
        int ins=1+helper(s1,s2,i,j-1,dp);
        int del=1+helper(s1,s2,i-1,j,dp);
        int rep=1+helper(s1,s2,i-1,j-1,dp);
            
        return dp[i][j] = min(ins,min(del,rep));
        
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return helper(word1,word2,n,m,dp);
    }
};