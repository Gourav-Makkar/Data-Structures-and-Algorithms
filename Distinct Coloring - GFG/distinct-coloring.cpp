//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    long long int helper(int curr,int r[],int g[],int b[],long long int prev,int N,vector<vector<long long int>>&dp)
    {
        if(curr==N)
          return 0;
        
        if(dp[curr][prev]!=-1)
             return dp[curr][prev];
        
        long long int red=LLONG_MAX,green=LLONG_MAX,blue=LLONG_MAX;
        
        if(prev!=1)
          red=r[curr]+helper(curr+1,r,g,b,1,N,dp);
        
        if(prev!=2)
          green=g[curr]+helper(curr+1,r,g,b,2,N,dp);
        
        if(prev!=3)
          blue=b[curr]+helper(curr+1,r,g,b,3,N,dp);
        
        return dp[curr][prev]=min(red,min(green,blue));
    }
    
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        
        vector<vector<long long int>>dp(N,vector<long long int>(4,-1));
        return helper(0,r,g,b,0,N,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends