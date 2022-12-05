//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check(int mx,int a[],int m,int n)
    {
        int cs=0;
        int ct=1;
        for(int i=0;i<n;i++)
        {
            if(cs+a[i]<=mx)
              cs+=a[i];
            else
            {
                ct++;
                cs=a[i];
            }
        }
        return ct<=m;
    }
    
    int findPages(int a[], int n, int m) 
    {
        //code here
        int st=INT_MIN,en=0;
        
        for(int i=0;i<n;i++)
        {
            st=max(st,a[i]);
            en+=a[i];
        }
        int ans=-1;
        if(n<m)
          return ans;
        if(m==1)
          return en;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            if(check(mid,a,m,n))
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