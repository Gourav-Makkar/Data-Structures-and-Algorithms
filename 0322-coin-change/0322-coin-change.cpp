class Solution {
public:
    
//     int helper(int idx,vector<int>&coins,int amount)
//     {
//         if(amount==0)
//             return 0;
//         if(idx==0)
//         {
//             if(amount%coins[idx]==0)
//                 return amount/coins[idx];
//             return 1e9;
//         }
//         int t=1e9;
//         if(coins[idx]<=amount)
//             t=1+helper(idx,coins,amount-coins[idx]);
//         int nt=helper(idx-1,coins,amount);
        
//         return min(t,nt);
//     }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        
        for(int i=0;i<n;i++)          //if my amount is 0, I don't need any coin
            dp[i][0]=0;
        
        for(int i=0;i<=amount;i++)
        {
            if(i>=coins[0] && i%coins[0]==0)
                dp[0][i]=i/coins[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j>=coins[i])
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i]]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n-1][amount]>=1e9)
            return -1;
        return dp[n-1][amount];
    }
};