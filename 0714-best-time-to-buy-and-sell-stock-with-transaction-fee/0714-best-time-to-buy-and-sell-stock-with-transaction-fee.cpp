class Solution {
public:
    
    int helper(vector<int>&prices,int idx,bool buy,int fee,vector<vector<int>>&dp)
    {
        if(idx==prices.size())
            return 0;
        
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        
        int take=0,notTake=0;
        
        if(!buy)
        {
            take=-prices[idx] + helper(prices,idx+1,true,fee,dp);
            notTake=helper(prices,idx+1,false,fee,dp);
        }
        else
        {
            take=prices[idx] + helper(prices,idx+1,false,fee,dp) - fee;
            notTake=helper(prices,idx+1,buy,fee,dp);
        }
        
        return dp[idx][buy]=max(take,notTake);
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return helper(prices,0,false,fee,dp);
    }
};