class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+2,1);
        
        for(int i=1;i<n+1;i++)
            v[i]=nums[i-1];
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=v[i-1]*v[i]*v[i+1];
        }
        
        for(int length=2;length<=n;length++)
        {
            for(int i=1;i<=n-length+1;i++)
            {
                int j=i+length-1;
                
                for(int k=i;k<=j;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+ v[i-1]*v[k]*v[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};