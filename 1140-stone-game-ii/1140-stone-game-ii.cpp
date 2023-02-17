class Solution {
public:
    
    int helper(int idx,int m,vector<int>&piles,vector<vector<int>>&dp)
    {
        int n=piles.size();
        if(idx>=n)
            return 0;
        
        if(dp[idx][m]!=-1)
            return dp[idx][m];
        
        if(idx+2*m >=n)
        {
            int sum=0;
            for(int i=idx;i<n;i++)
                sum+=piles[i];
            return dp[idx][m]=sum;
        }
        
        int sum=0,ans=INT_MIN;
        
        for(int i=1;i<=2*m;i++)
        {
            sum+=piles[idx+i-1];
            ans=max(ans,sum-helper(idx+i,max(m,i),piles,dp));
        }
        return dp[idx][m]=ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(2*n,-1));
            
        int dif=helper(0,1,piles,dp);
        int sum=0;
        for(auto it:piles)
            sum+=it;
        
        return (sum+dif)/2;
    }
};