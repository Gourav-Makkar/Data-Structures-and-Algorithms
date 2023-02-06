class Solution {
public:
    
//     int helper(int idx,vector<int>&coins,int amount)
//     {
//         if(idx==0)
//             return (amount%coins[0]==0);
//         int t=0;
//         if(amount>=coins[idx])
//            t=helper(idx,coins,amount-coins[idx]);
//         int nt=helper(idx-1,coins,amount);
        
//         return t+nt;
//     }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // return helper(n-1,coins,amount);
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        
        for(int i=0;i<=amount;i++)
        {
            if(coins[0]<=i && i%coins[0]==0)
                dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i]<=j)
                    dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n-1][amount];
    }
};