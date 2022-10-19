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
    
    //  bool helper(vector<int>arr,int idx,int target,vector<vector<int>>&dp)
    // {
    //     if(target==0)
    //       return true;
          
    //     if(idx==0)
    //       return arr[idx]==target;
          
    //     if(dp[idx][target]!=-1)
    //       return dp[idx][target];
          
    //     bool notTake=helper(arr,idx-1,target,dp);
    //     bool take=false;
    //     if(target>=arr[idx])
    //       take=helper(arr,idx-1,target-arr[idx],dp);
    //     return dp[idx][target]= notTake || take;
    // }

//   TABULATION
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        // vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
      
        // // return helper(arr,n-1,sum,dp);
        
        // for(int i=0;i<n;i++)
        //   dp[i][0]=true;
          
        // dp[0][arr[0]]=true;
        
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=1;j<=sum;j++)
        //     {
        //         bool notTake=dp[i-1][j];
        //         bool take=false;
        //         if(j>=arr[i])
        //           take=dp[i-1][j-arr[i]];
        //         dp[i][j]=take || notTake; 
        //     }
        // }
        // return dp[n-1][sum];
        
        // SPACE OPTIMIZED
        
        vector<bool>prev(sum+1,false);
        prev[0]=true;
        for(int i=0;i<n;i++)
        {
            vector<bool>curr(sum+1,false);
            curr[0]=true;
            for(int target=1;target<=sum;target++)
            {
                bool notTake=prev[target];
                bool take=false;
                if(target>=arr[i])
                 take=prev[target-arr[i]];
                curr[target]=take||notTake;
            }
            prev=curr;
        }
        return prev[sum];
        
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