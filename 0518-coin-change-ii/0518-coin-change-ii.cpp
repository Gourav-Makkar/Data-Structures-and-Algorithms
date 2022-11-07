class Solution {
public:
    
    int helper(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            if(amount%coins[0]==0)
                return 1;
            return 0;
        }
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
        int nt=helper(coins,amount,idx-1,dp);
        int t=0;
        if(coins[idx]<=amount)
           t=helper(coins,amount-coins[idx],idx,dp);
        return dp[idx][amount]=t+nt;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,amount,n-1,dp);
    }
};