//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool check(int mid,int arr[],int n,int m)
    {
        int ct=1,cs=0;
        
        for(int i=0;i<n;i++)
        {
            if(cs+arr[i]>mid)
            {
                cs=arr[i];
                ct++;
            }
            else
              cs+=arr[i];
        }
        return ct<=m;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        if(m>n)
          return -1;
          
        int st=INT_MIN,en=0;
        
        for(int i=0;i<n;i++)
        {
            st=max(st,arr[i]);
            en+=arr[i];
        }
        
        int ans;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(mid,arr,n,m))
            {
                ans=mid;
                en=mid-1;
            }
            else
              st=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends