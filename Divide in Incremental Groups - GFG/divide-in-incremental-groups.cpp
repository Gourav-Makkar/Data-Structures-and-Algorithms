//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int helper(int n,int curr,int k,vector<vector<vector<int>>>&dp)
    {
        if(n==0 && k==0)
          return 1;
        
        if(n<=0 || k==0 || curr>n)
          return 0;
        
        if(dp[n][curr][k]!=-1)
          return dp[n][curr][k];
        
        int take=helper(n-curr,curr,k-1,dp);
        int nottake=helper(n,curr+1,k,dp);
        
        return dp[n][curr][k]=take+nottake;
    }
  
    int countWaystoDivide(int n, int k) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return helper(n,1,k,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends