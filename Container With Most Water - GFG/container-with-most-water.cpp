//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int n)
{
    // Your code goes here
    long long ans=0;
    
    int st=0,en=n-1;
    
    while(st<en)
    {
        if(a[st]<=a[en])
        {
            ans=max(ans,a[st]*(en-st));
            st++;
        }
        else
        {
            ans=max(ans,a[en]*(en-st));
            en--;
        }
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends