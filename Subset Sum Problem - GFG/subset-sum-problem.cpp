//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool helper(vector<int>&arr,int idx,int sum,vector<vector<int>>&dp)
    {
        if(sum<0)
           return false;
        if(sum==0)
          return true;
        if(idx==arr.size())
          return false;
         if(dp[idx][sum]!=-1)
           return dp[idx][sum];
         
        bool pick= helper(arr,idx+1,sum-arr[idx],dp);
        bool notPick= helper(arr,idx+1,sum,dp);
        
        return dp[idx][sum]=(pick|| notPick);
        
    }
     
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(101,vector<int>(100001,-1));
        return helper(arr,0,sum,dp);
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