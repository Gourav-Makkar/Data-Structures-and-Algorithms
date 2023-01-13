//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        
        sort(v.begin(),v.end());
        int ans=INT_MIN;
        int mnIdx=v[0].second;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,v[i].second-mnIdx);
            mnIdx=min(mnIdx,v[i].second);
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends