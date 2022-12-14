class Solution {
public:
    
    int helper(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e9;
        }
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
        int nt=0+helper(coins,amount,idx-1,dp);
        int t=1e9;
        if(coins[idx]<=amount)
            t=1+helper(coins,amount-coins[idx],idx,dp);
        return dp[idx][amount]=min(t,nt);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(coins,amount,n-1,dp);
        if(ans>=1e9)
            return -1;
        return ans;
    }
};