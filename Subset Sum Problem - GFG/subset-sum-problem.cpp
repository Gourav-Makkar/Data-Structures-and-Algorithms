//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    // bool helper(vector<int>&arr,int idx,int target,vector<vector<int>>&dp)
    // {
    //     if(target==0)
    //       return true;
    //     if(idx==0)
    //       return arr[0]==target;
          
    //     if(dp[idx][target]!=-1)
    //       return dp[idx][target];
    //     bool pick=helper(arr,idx-1,target-arr[idx],dp);
    //     bool notPick=helper(arr,idx-1,target,dp);
        
    //     return dp[idx][target]=pick||notPick;
    // }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        // return helper(arr,n-1,sum,dp);
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(arr[0]<=sum)
          dp[0][arr[0]]=true;
        
        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notPick=dp[idx-1][target];
                bool pick=false;
                if(arr[idx]<=target)
                   pick=dp[idx-1][target-arr[idx]];
                
                dp[idx][target]=pick||notPick;
            }
        }
        return dp[n-1][sum];
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