//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   int helper(int cr,int cc,vector<vector<int>>&grid,vector<vector<int>>&dp)
   {
       int n=grid.size(),m=grid[0].size();
       if(cr<0 || cr==n || cc<0 || cc==m || grid[cr][cc]==0)
         return 0;
       if(cr==n-1 && cc==m-1)
         return 1;
       
       if(dp[cr][cc]!=-1)
        return dp[cr][cc];  
       
       return dp[cr][cc]=(helper(cr+1,cc,grid,dp)+helper(cr,cc+1,grid,dp))%(1000000007);
   }
  
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[0][0]==0 || grid[n-1][m-1]==0)
          return 0;
          
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends