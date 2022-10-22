//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//   MEMOIZATION
  
    // int helper(int N,vector<int>&dp)
    // {
    //     if(N==0)
    //       return 1;
    //     if(dp[N]!=-1)
    //       return dp[N];
    //     int first=(helper(N-1,dp))%100000000;
    //     int second=0;
    //     if(N>1)
    //       second=(helper(N-2,dp))%100000000;
    //     return dp[N]=(first+second)%100000000;
    // }
    
    // TABULATION
    int fillingBucket(int N) {
        // code here
        // vector<int>dp(N+1,0);
        // return helper(N,dp);
        // dp[0]=1;
        // for(int i=1;i<=N;i++)
        // {
        //   int first=dp[i-1]%100000000;
        //   int second=0;
        //   if(i>1)
        //     second=dp[i-2]%100000000;
        //   dp[i]=(first+second)%100000000;
        // }
        // return dp[N];
        
        // SPACE OPTIMIZED
        
        int prev2=0,prev=1;
        for(int i=1;i<=N;i++)
        {
            int curr=(prev+prev2)%100000000;
            prev2=prev;
            prev=curr;
        }
        return prev;
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