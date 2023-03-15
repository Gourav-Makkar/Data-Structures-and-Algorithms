class Solution {
public:
    
    int helper(int i,int j,vector<int>&cuts,int st,int en,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int cost=INT_MAX;
        
        for(int k=i;k<=j;k++)
        {
            cost=min(cost,helper(i,k-1,cuts,st,cuts[k],dp) + (en-st) + helper(k+1,j,cuts,cuts[k],en,dp));
        }
        return dp[i][j]=cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int s=cuts.size();
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>>dp(s,vector<int>(s,-1));
        
        return helper(0,s-1,cuts,0,n,dp);
    }
};