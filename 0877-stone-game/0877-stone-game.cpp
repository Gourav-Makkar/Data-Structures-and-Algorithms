class Solution {
public:
    
    int helper(int st,int en,vector<int>&piles,vector<vector<int>>&dp)
    {
        if(st>en)
            return 0;
        if(st==en)
            return piles[st];
        
        if(dp[st][en]!=-1)
            return dp[st][en];
        
        int first=piles[st]+helper(st+2,en,piles,dp);
        int second=piles[st]+helper(st+1,en-1,piles,dp);
        int third=piles[en]+helper(st+1,en-1,piles,dp);
        int fourth=piles[en]+helper(st,en-2,piles,dp);
        
        return dp[st][en]=max(first,max(second,max(third,fourth)));
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        
        int st=0,en=n-1;
        int sum=0;
        for(auto it:piles)
            sum+=it;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ct=helper(st,en,piles,dp);
        
        if(ct>sum/2)
            return true;
        return false;
    }
};