//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
    long long helper(int n,vector<int>&arr,int k)
    {
        unordered_map<int,int>m;
        long long cs=0,ans=0,curr=0;
        m[0]=1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=k)
            {
                curr+=m[cs];
                cs++;
            }
            else
            {
                curr-=m[cs-1];
                cs--;
            }
            ans+=curr;
            m[cs]++;
        }
        return ans;
    }
  
    long long countSubarray(int n,vector<int> arr,int k) {
        long long ct1=helper(n,arr,k);
        long long ct2=helper(n,arr,k+1);
        
        return ct1-ct2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends