class Solution {
public:
    
    bool helper(string s,string p,int idx1,int idx2,vector<vector<int>>&dp)
    {
        if(idx2==0 && idx1==0)
            return true;
        
        if(idx2==0 && idx1>0)
            return false;
            
        if(idx1==0 && idx2>0)
        {
            for(int i=1;i<=idx2;i++)
            {
                if(p[i-1]!='*')
                    return false;
            }
            return true;
        } 
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(s[idx1-1]==p[idx2-1] || p[idx2-1]=='?')
            return dp[idx1][idx2]=helper(s,p,idx1-1,idx2-1,dp);
        
        if(p[idx2-1]=='*')
        {
            bool f=helper(s,p,idx1,idx2-1,dp);
            bool sec=helper(s,p,idx1-1,idx2,dp);
            
            return dp[idx1][idx2]=f || sec;
        }
        return  dp[idx1][idx2]=false;
        
    }
    
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        // return helper(s,p,n,m,dp);
        
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
            dp[i][0]=false;
        
        for(int i=1;i<=m;i++)
        {
            bool flag=true;
            for(int j=1;j<=i;j++)
            {
                if(p[j-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                dp[0][i]=true;
        }
        
        for(int idx1=1;idx1<=n;idx1++)
        {
            for(int idx2=1;idx2<=m;idx2++)
            {
                if(s[idx1-1]==p[idx2-1] || p[idx2-1]=='?')
                   dp[idx1][idx2]=dp[idx1-1][idx2-1];
                
                else if(p[idx2-1]=='*')
                {
                    bool f=dp[idx1][idx2-1];
                    bool sec=dp[idx1-1][idx2];
                    
                    dp[idx1][idx2]=f || sec;
                }
                else  
                    dp[idx1][idx2]=false;
            }
        }
        return dp[n][m];
    }
};