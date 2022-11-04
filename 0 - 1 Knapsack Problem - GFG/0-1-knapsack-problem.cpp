//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int helper(int wt[],int val[],int n,int w,int idx,vector<vector<int>>&dp)
    {
        if(idx==n-1)
        {
            if(w>=wt[idx])
              return val[idx];
            return 0;
        }
        if(dp[idx][w]!=-1)
          return dp[idx][w];
        
        int notPick=0+helper(wt,val,n,w,idx+1,dp);
        int pick=0;
        if(w>=wt[idx])
          pick=val[idx]+helper(wt,val,n,w-wt[idx],idx+1,dp);
           
        return dp[idx][w]=max(pick,notPick);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
      return helper(wt,val,n,W,0,dp);
        
    //   for(int i=0;i<n;i++)
    //       dp[i][0]=0;
    //   if(W>=wt[n-1])
    //       dp[n-1][W]=val
        
    //   for(int idx=n-1;idx>=0;idx--)
    //   {
    //       for(int w=W;w>=1;w--)
    //       {
                
    //       }
    //   }
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends