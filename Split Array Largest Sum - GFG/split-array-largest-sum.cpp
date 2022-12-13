//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool check(int val,int arr[],int n,int k)
    {
        int cs=0;
        int ct=1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>val)
              return false;
              
            if(cs+arr[i]<=val)
            {
                cs+=arr[i];
            }
            else
            {
                ct++;
                cs=arr[i];
            }
        }
        return ct<=k;
    }
  
    int splitArray(int arr[] ,int n, int k) {
        // code here
        
        int st=INT_MAX,en=0;
        
        for(int i=0;i<n;i++)
        {
            st=min(st,arr[i]);
            en+=arr[i];
        }
        int ans;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(mid,arr,n,k))
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
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends