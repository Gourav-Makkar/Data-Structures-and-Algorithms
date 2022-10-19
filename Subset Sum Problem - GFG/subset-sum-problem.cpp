//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

// START FROM 0

    // bool helper(vector<int>arr,int idx,int target,int n,vector<vector<int>>&dp)
    // {
    //     if(target==0)
    //       return true;
          
    //     if(idx==n)
    //       return false;
         
    //     if(dp[idx][target]!=-1)
    //       return dp[idx][target];
          
    //     if(helper(arr,idx+1,target-arr[idx],n,dp) || helper(arr,idx+1,target,n,dp))
    //       return dp[idx][target]=true;
          
    //     return dp[idx][target]=false;
    // }
    
    
    // START FROM BACK
    
     bool helper(vector<int>arr,int idx,int target,vector<vector<int>>&dp)
    {
        if(target==0)
          return true;
          
        if(idx==0)
          return arr[idx]==target;
          
        if(dp[idx][target]!=-1)
          return dp[idx][target];
          
        bool notTake=helper(arr,idx-1,target,dp);
        bool take=false;
        if(target>=arr[idx])
          take=helper(arr,idx-1,target-arr[idx],dp);
        return dp[idx][target]= notTake || take;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(101,vector<int>(100001,-1));
      
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