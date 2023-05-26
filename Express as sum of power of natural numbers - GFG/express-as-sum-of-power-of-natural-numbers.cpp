//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod=1000000007;
    int helper(int curr,int n,int x,vector<vector<int>>&dp)
    {
        if(n==0)
          return 1;
        
        int val=pow(curr,x);
        if(val>n)
          return 0;
          
        if(dp[curr][n]!=-1)
          return dp[curr][n];
        
        int take=0,nottake=0;
        
        take=helper(curr+1,n-val,x,dp);
        
        nottake=helper(curr+1,n,x,dp);
        
        return dp[curr][n]=(take+nottake)%mod;
    }
    
    int numOfWays(int n, int x)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends