//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool helper(vector<int>&arr,int idx,int target,vector<vector<int>>&dp)
    {
        if(target==0)
          return true;
        if(idx==0)
          return arr[0]==target;
          
        if(dp[idx][target]!=-1)
          return dp[idx][target];
        bool pick=helper(arr,idx-1,target-arr[idx],dp);
        bool notPick=helper(arr,idx-1,target,dp);
        
        return dp[idx][target]=pick||notPick;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,n-1,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends