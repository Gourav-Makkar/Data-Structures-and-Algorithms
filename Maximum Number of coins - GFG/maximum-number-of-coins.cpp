//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    int helper(int i,int j,vector<int>&a,vector<vector<int>>&dp)
    {
        if(i>j)
          return 0;
          
        if(dp[i][j]!=-1)
          return dp[i][j];
          
        int coins=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            coins=max(coins,helper(i,k-1,a,dp)+a[i-1]*a[k]*a[j+1]+helper(k+1,j,a,dp));
        }
        return dp[i][j]=coins;
    }
    
    
    int maxCoins(int N, vector <int> &a)
    {
        a.insert(a.begin(),1);
        a.push_back(1);
        
        vector<vector<int>>dp(N+2,vector<int>(N+2,-1));
        return helper(1,N,a,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends