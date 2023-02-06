//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int helper(int idx,int wt[],int val[],int W)
    {
        if(idx==0)
        {
            if(W>=wt[0])
              return val[0];
            else
              return 0;
        }
        int t=0;
        if(W>=wt[idx])
          t=val[idx]+helper(idx-1,wt,val,W-wt[idx]);
        int nt=helper(idx-1,wt,val,W);
        
        return max(t,nt);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return helper(n-1,wt,val,W);
      vector<vector<int>>dp(n,vector<int>(W+1,-1));
      
      for(int i=0;i<n;i++)
        dp[i][0]=0;
      for(int i=0;i<=W;i++)
      {
          if(i>=wt[0])
            dp[0][i]=val[0];
          else
            dp[0][i]=0;
      }
      
      for(int i=1;i<n;i++)
      {
          for(int j=1;j<=W;j++)
          {
              if(wt[i]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i]]+val[i]);
               else
                 dp[i][j]=dp[i-1][j];
          }
      }
      return dp[n-1][W];
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