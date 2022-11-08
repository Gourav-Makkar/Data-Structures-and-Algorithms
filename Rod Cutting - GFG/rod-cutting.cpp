//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int helper(int price[],int idx,int len,vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            return len*price[0];
        }
        if(dp[idx][len]!=-1)
          return dp[idx][len];
        int nt=0+helper(price,idx-1,len,dp);
        int t=0;
        if(idx+1<=len)
          t=price[idx]+helper(price,idx,len-idx-1,dp);
        
        return dp[idx][len]=max(nt,t);
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        // return helper(price,n-1,n,dp);
        for(int i=0;i<=n;i++)
          dp[0][i]=i*price[0];
        for(int idx=1;idx<n;idx++)
        {
            for(int len=1;len<=n;len++)
            {
                int nt=0+dp[idx-1][len];
                int t=0;
                if(idx+1<=len)
                  t=price[idx]+dp[idx][len-idx-1];
                
               dp[idx][len]=max(nt,t);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends