class Solution {
public:
    
    long long helper(int idx,vector<vector<int>>& questions,int n,vector<long long>&dp)
    {
        if(idx>=n)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        long long take=questions[idx][0]+helper(idx+questions[idx][1]+1,questions,n,dp);
        long long notTake=helper(idx+1,questions,n,dp);
        
        return dp[idx]=max(take,notTake);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        
        vector<long long>dp(n,-1);
        return helper(0,questions,n,dp);
    }
};