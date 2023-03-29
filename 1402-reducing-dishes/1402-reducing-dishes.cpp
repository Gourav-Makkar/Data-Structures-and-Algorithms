class Solution {
public:
    
    int helper(int idx,vector<int>&arr,int ct,vector<vector<int>>&dp)
    {
        if(idx==arr.size())
            return 0;
        
        if(dp[idx][ct]!=-1)
            return dp[idx][ct];
        
        int take=ct*arr[idx]+helper(idx+1,arr,ct+1,dp);
        int nottake=helper(idx+1,arr,ct,dp);
        
        return  dp[idx][ct]=max(take,nottake);
    }
    
    int maxSatisfaction(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return helper(0,arr,1,dp);
    }
};