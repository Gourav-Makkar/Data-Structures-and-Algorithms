class Solution {
public:
    
    int helper(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(idx==0)
        {
           if(amount%coins[0]==0)
               return amount/coins[0];
           else
               return 1e9;
        }
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
        int notTake=0+helper(coins,amount,idx-1,dp);
        int take=1e9;
        
        if(amount>=coins[idx])
            take=1+helper(coins,amount-coins[idx],idx,dp);
        
        return dp[idx][amount]=min(notTake,take);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans=helper(coins,amount,n-1,dp);
        // if(ans==1e9)
        //     return -1;
        // return ans;
        
        for(int i=1;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            else
                dp[0][i]=1e9;
        }
        
        for(int idx=1;idx<n;idx++)
        {
            for(int tar=0;tar<=amount;tar++)
            {
                int notTake=0+dp[idx-1][tar];
                int take=1e9;
                if(tar>=coins[idx])
                    take=1+dp[idx][tar-coins[idx]];
                dp[idx][tar]=min(notTake,take);
            }
        }
        if(dp[n-1][amount]==1e9)
            return -1;
        return dp[n-1][amount];
    }
};