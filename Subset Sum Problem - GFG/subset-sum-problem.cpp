//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool helper(vector<int>&arr,int sum,int idx,vector<vector<int>>&dp)
    {
        if(sum==0)
          return true;
        if(idx==0)
        {
            if(sum==arr[0])
              return true;
            return false;
        }
        if(dp[idx][sum]!=-1)
          return dp[idx][sum];
       
        bool notPick=helper(arr,sum,idx-1,dp);
        bool pick=false;
        if(arr[idx]<=sum)
           pick=helper(arr,sum-arr[idx],idx-1,dp);
        
        
        return dp[idx][sum]=pick||notPick;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        // return helper(arr,sum,n-1,dp);
        for(int i=0;i<n;i++)
          dp[i][0]=true;
        if(arr[0]<=sum)
          dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int tar=1;tar<=sum;tar++)
            {
                bool notPick=dp[i-1][tar];
                bool pick=false;
                if(arr[i]<=tar)
                   pick=dp[i-1][tar-arr[i]];
                
                
                dp[i][tar]=pick||notPick;
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