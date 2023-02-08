class Solution {
public:
    
    int helper(int st,int en,vector<int>&v,vector<vector<int>>&dp)
    {
        if(st>en)
            return 0;
        
        if(dp[st][en]!=-1)
            return dp[st][en];
        int ans=INT_MIN;
        for(int k=st;k<=en;k++)
        {
            ans=max(ans,helper(st,k-1,v,dp) + v[st-1]*v[k]*v[en+1] + helper(k+1,en,v,dp));
        }
        return dp[st][en]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+2,1);
        
        for(int i=1;i<n+1;i++)
            v[i]=nums[i-1];
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return helper(1,n,v,dp);
        
//         for(int i=1;i<=n;i++)
//         {
//             dp[i][i]=v[i-1]*v[i]*v[i+1];
//         }
        
//         for(int length=2;length<=n;length++)
//         {
//             for(int i=1;i<=n-length+1;i++)
//             {
//                 int j=i+length-1;
                
//                 for(int k=i;k<=j;k++)
//                 {
//                     dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+ v[i-1]*v[k]*v[j+1]);
//                 }
//             }
//         }
//         return dp[1][n];
    }
};