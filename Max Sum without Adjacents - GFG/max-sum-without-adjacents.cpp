// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
// 	int helper(vector<int>arr,int idx,vector<int>&dp)
// 	{
// 	    if(idx==0)
// 	      return arr[0];
// 	    if(idx<0)
// 	      return 0;
// 	    if(dp[idx]!=-1)
// 	      return dp[idx];
// 	    int pick=arr[idx]+helper(arr,idx-2,dp);
// 	    int nonPick=0+helper(arr,idx-1,dp);
	    
// 	    return dp[idx]=max(pick,nonPick);
// 	}
	
	int findMaxSum(int *arr, int n) {
	    
	   int prev=arr[0];
	   int prev2=0;
	   for(int i=1;i<n;i++)
	   {
	       int pick=arr[i];
	       if(i>=2)
	         pick+=prev2;
	       int nonPick=0+prev;
	       
	       int curr=max(pick,nonPick);
	       prev2=prev;
	       prev=curr;
	   }
	   return prev;
	    // code here
	   // vector<int>v(n);
	   // vector<int>dp(n,0);
	   // for(int i=0;i<n;i++)
	   // {
	   //     v[i]=arr[i];
	   // }
	   
	   //dp[0]=arr[0];
	   //for(int i=1;i<n;i++)
	   //{
	       
	   //    int pick=arr[i];
	   //    if(i>=2)
	   //      pick+=dp[i-2];
	   //    int nonPick=0+dp[i-1];
	       
	   //    dp[i]=max(pick,nonPick);
	   //}
	   
	   //return dp[n-1];
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends