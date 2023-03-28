class Solution {
public:
    
    int helper(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp)
    {
        if(idx==days.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int idx1=upper_bound(days.begin(),days.end(),days[idx]+6)-days.begin();
        int idx2=upper_bound(days.begin(),days.end(),days[idx]+29)-days.begin();
        
        int first=costs[0]+helper(idx+1,days,costs,dp);
        int second=costs[1]+helper(idx1,days,costs,dp);
        int third=costs[2]+helper(idx2,days,costs,dp);
        
        return dp[idx]=min(first,min(second,third));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return helper(0,days,costs,dp);
    }
};