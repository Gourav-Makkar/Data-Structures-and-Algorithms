class Solution {
public:
    
    // bool check(int n)
    // {
    //     for(int i=1;i*i<=n;i++)
    //     {
    //         if(i*i==n)
    //             return true;
    //     }
    //     return false;
    // }
    
    int helper(vector<int>&sq,int idx,int n,vector<vector<int>>&dp)
    {
        if(n==0 || n==1)
            return n;
        if(idx<0)
            return 1e9;
        
        if(dp[idx][n]!=-1)
            return dp[idx][n];
        
        int take=1e9;
        if(sq[idx]<=n)
           take=1+helper(sq,idx,n-sq[idx],dp);
        int notTake=helper(sq,idx-1,n,dp);
        
        return dp[idx][n]=min(take,notTake);
            
    }
    
    int numSquares(int n) {
        
        vector<int>squares;
        for(int i=1;i*i<=n;i++)
        {
           squares.push_back(i*i);
        }
        int x=squares.size();
        vector<vector<int>>dp(x+1,vector<int>(n+1,-1));
        return helper(squares,x-1,n,dp);
    }
};