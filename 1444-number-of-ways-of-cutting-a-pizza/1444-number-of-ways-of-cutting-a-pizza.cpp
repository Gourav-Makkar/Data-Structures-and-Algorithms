class Solution {
public:
    int mod=1000000007;
    bool hasApple(int sr,int er,int sc,int ec,vector<string>&pizza)
    {
        for(int i=sr;i<=er;i++)
        {
            for(int j=sc;j<=ec;j++)
            {
                if(pizza[i][j]=='A')
                    return true;
            }
        }
        return false;
    }
    
    int helper(int cr,int cc,vector<string>&pizza,int k,vector<vector<vector<int>>>&dp)
    {
        int r=pizza.size(),c=pizza[0].size();
        
        if(k==1)
        {
            for(int i=cr;i<r;i++)
            {
                for(int j=cc;j<c;j++)
                {
                    if(pizza[i][j]=='A')
                        return 1;
                }
            }
            return 0;
        }
        
        if(dp[cr][cc][k]!=-1)
            return dp[cr][cc][k];
        
        long long ans=0;
        
        for(int i=cr;i<r-1;i++)
        {
           bool val=hasApple(cr,i,cc,c-1,pizza);
           if(val)
             ans=(ans+helper(i+1,cc,pizza,k-1,dp))%mod;
        }
        
        for(int i=cc;i<c-1;i++)
        {
            bool val=hasApple(cr,r-1,cc,i,pizza);
            if(val)
                ans=(ans+helper(cr,i+1,pizza,k-1,dp))%mod;
        }
        
        return dp[cr][cc][k]=ans;
    }
    
    int ways(vector<string>& pizza, int k) {
       int r=pizza.size(),c=pizza[0].size();
        
       vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(k+1,-1)));
       return helper(0,0,pizza,k,dp);
    }
};