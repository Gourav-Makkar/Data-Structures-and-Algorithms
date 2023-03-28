class Solution {
public:
    
    int helper(int idx,vector<int>&days,vector<int>&costs,int avail,vector<vector<int>>&dp)
    {
        if(idx==days.size())
            return 0;
        
        if(dp[idx][avail]!=-1)
            return dp[idx][avail];
        
        if(days[idx]<=avail)
            return dp[idx][avail]=helper(idx+1,days,costs,avail,dp);
        
        int first=costs[0]+helper(idx+1,days,costs,days[idx],dp);
        int second=costs[1]+helper(idx+1,days,costs,days[idx]+7-1,dp);
        int third=costs[2]+helper(idx+1,days,costs,days[idx]+30-1,dp);
        
        return dp[idx][avail]=min(first,min(second,third));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>>dp(days.size(),vector<int>(396,-1));
        return helper(0,days,costs,0,dp);
    }
};