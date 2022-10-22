//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int helper(int N,vector<int>&dp)
    {
        if(N==0)
          return 1;
        if(dp[N]!=-1)
          return dp[N];
        int first=(helper(N-1,dp))%100000000;
        int second=0;
        if(N>1)
          second=(helper(N-2,dp))%100000000;
        return dp[N]=(first+second)%100000000;
    }
    
    int fillingBucket(int N) {
        // code here
        vector<int>dp(N+1,-1);
        return helper(N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends