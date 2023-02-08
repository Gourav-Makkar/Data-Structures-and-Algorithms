class Solution {
public:
    
    int helper(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp)
    {
        if(idx1==0 && idx2==0)
          return 0;
        
        if(idx1==0)
          return idx2;
        
        if(idx2==0)
            return idx1;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(s1[idx1-1]==s2[idx2-1])
            return dp[idx1][idx2]=helper(idx1-1,idx2-1,s1,s2,dp);
        
        else
        {
            int ins=1+helper(idx1,idx2-1,s1,s2,dp);
            int del=1+helper(idx1-1,idx2,s1,s2,dp);
            int rep=1+helper(idx1-1,idx2-1,s1,s2,dp);
            
            return dp[idx1][idx2]=min(ins,min(del,rep));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        // return helper(n1,n2,word1,word2,dp);
        
        for(int i=1;i<=n1;i++)
            dp[i][0]=i;
        
        for(int i=1;i<=n2;i++)
            dp[0][i]=i;
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
                }
            }
        }
        return dp[n1][n2];
    }
};