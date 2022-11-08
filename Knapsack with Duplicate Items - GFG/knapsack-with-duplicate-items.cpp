//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int helper(int val[],int wt[],int w,int idx,vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            if(wt[0]<=w)
            {
                 return ((w/wt[0])*val[0]);
            }
            return 0;
        }
        if(dp[idx][w]!=-1)
          return dp[idx][w];
        int nt=0+helper(val,wt,w,idx-1,dp);
        int t=0;
        if(wt[idx]<=w)
          t=val[idx]+helper(val,wt,w-wt[idx],idx,dp);
          
        return dp[idx][w]=max(t,nt);
    }
     
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return helper(val,wt,W,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends