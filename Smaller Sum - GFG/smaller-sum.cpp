//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        map<int,long long>m;
        for(auto it:arr)
          m[it]++;
        
        long long ps=0;
        
        for(auto &it:m)
        {
            long long temp=it.second*it.first;
            it.second=ps;
            ps+=temp;
        }
        
        // for(auto it:m)
        //  cout<<it.first<<" : "<<it.second<<endl;
        
        vector<long long>ans(n);
        
        for(int i=0;i<n;i++)
          ans[i]=m[arr[i]];
          
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends