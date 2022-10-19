//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool helper(vector<int>arr,int idx,int target,int n,vector<vector<int>>&dp)
    {
        if(target==0)
          return true;
          
        if(idx==n)
          return false;
         
        if(dp[idx][target]!=-1)
          return dp[idx][target];
          
        if(helper(arr,idx+1,target-arr[idx],n,dp) || helper(arr,idx+1,target,n,dp))
          return dp[idx][target]=true;
        return dp[idx][target]=false;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(101,vector<int>(100001,-1));
      
        return helper(arr,0,sum,n,dp);
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