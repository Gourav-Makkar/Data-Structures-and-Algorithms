//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    
    int helper(int wt[],int val[],int w,int idx,vector<vector<int>>&dp)
    {
        if(idx==0)
         {
              if(wt[0]<=w)
                return val[0];
              return 0;
         }
          
        if(dp[idx][w]!=-1)
          return dp[idx][w];
        int nottake=0+helper(wt,val,w,idx-1,dp);
        int take=0;
        if(wt[idx]<=w)
          take=val[idx]+helper(wt,val,w-wt[idx],idx-1,dp);
        
        return dp[idx][w]=max(nottake,take);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return helper(wt,val,W,n-1,dp);
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