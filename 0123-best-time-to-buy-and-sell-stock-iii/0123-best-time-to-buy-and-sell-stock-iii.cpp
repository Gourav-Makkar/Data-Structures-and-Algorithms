class Solution {
public:
    
    int helper(vector<int>&prices,int idx,bool buy,int trans,vector<vector<vector<int>>>&dp)
    {
        if(trans==0 || idx==prices.size())
            return 0;
        
        if(dp[idx][buy][trans]!=-1)
            return dp[idx][buy][trans];
        
        int take=0,notTake=0;
        
        if(!buy)
        {
            take=-prices[idx]+helper(prices,idx+1,true,trans,dp); // buy
            notTake=helper(prices,idx+1,buy,trans,dp);           //not buy
        }
        else
        {
            take=prices[idx]+helper(prices,idx+1,false,trans-1,dp); //sell
            notTake=helper(prices,idx+1,buy,trans,dp);           //not sell
        }
        
        return dp[idx][buy][trans]=max(take,notTake);
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        
        return helper(prices,0,false,2,dp);
    }
};