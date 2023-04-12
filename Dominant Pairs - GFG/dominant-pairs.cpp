//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        int mid=n/2;
        int ans=0;
        
        sort(arr.begin(),arr.begin()+mid);
        
        for(int i=n/2;i<n;i++)
        {
            int val=5*arr[i];
            int idx=lower_bound(arr.begin(),arr.begin()+mid,val)-arr.begin();
            ans+=mid-idx;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends