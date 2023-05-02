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
            if(cs+arr[i]<=mid)
              cs+=arr[i];
            
            else
            {
                ct++;
                cs=arr[i];
            }
        }
        if(cs>mid)
          return false;
        return ct<=m;
    }
    
    int findPages(int a[], int n, int m) 
    {
        int st=INT_MAX,en=0,ans=-1;
        
        if(m>n)
          return -1;
        
        for(int i=0;i<n;i++)
        {
            st=min(st,a[i]);
            en+=a[i];
        }
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(mid,a,n,m))
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