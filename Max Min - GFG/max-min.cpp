//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
   int mx=INT_MIN;
   int mn=INT_MAX;
    int findSum(int A[], int N)
    {
    	//code here.
    	for(int i=0;i<N;i++)
    	{
    	    mx=max(mx,A[i]);
    	    mn=min(mn,A[i]);
    	}
    	return mx+mn;
    	
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends