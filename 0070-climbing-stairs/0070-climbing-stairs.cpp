class Solution {
public:
//     MEMOIZATION
    // int helper(int n,vector<int>&dp)
    // {
    //     if(n==0 || n==1)
    //         return 1;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     return (dp[n]=helper(n-1,dp)+helper(n-2,dp));
    // }
    
//     TABULATION
    int climbStairs(int n) {
        if(n==1)
            return 1;
        int prev2=1,prev=1;
        for(int i=2;i<=n;i++)
        {
            int cur=prev2+prev;
            prev2=prev;
            prev=cur;
        }
        return prev;  
    }
};