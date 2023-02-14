//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int helper(vector<vector<int>>&colors,int idx,int prev,vector<vector<int>>&dp)
    {
        if(idx<0)
          return 0;
        
        if(dp[idx][prev]!=-1)
          return dp[idx][prev];
        
        int f=1e9,s=1e9,t=1e9;
        if(prev!=0)
          f=colors[idx][0]+helper(colors,idx-1,0,dp);
       
        if(prev!=1)
          s=colors[idx][1]+helper(colors,idx-1,1,dp);
          
        if(prev!=2)
          t=colors[idx][2]+helper(colors,idx-1,2,dp);
          
        return dp[idx][prev]=min(f,min(s,t)); 
    }

    int minCost(vector<vector<int>> &colors, int N) {
       int prev=3;
       
       vector<vector<int>>dp(N,vector<int>(4,-1));
       return helper(colors,N-1,prev,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends