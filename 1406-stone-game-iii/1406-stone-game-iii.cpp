class Solution {
public:
    
    int helper(int idx,vector<int>&arr,int n,unordered_map<int,int>&dp)
    {
        if(idx>=n)
            return 0;
        
        if(dp.find(idx)!=dp.end())
            return dp[idx];
        
        int ans=INT_MIN,p=0;
        for(int i=1;i<=3;i++)
        {
            if(idx+i>n)
                break;
            
            p+=arr[idx+i-1];
            int f=helper(idx+i+1,arr,n,dp);
            int s=helper(idx+i+2,arr,n,dp);
            int t=helper(idx+i+3,arr,n,dp);
            
            ans=max(ans,p+min(f,min(s,t)));
        }
        return dp[idx]=ans;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        
        unordered_map<int,int>dp;
        int alice=helper(0,stoneValue,n,dp);
        
//         cout<<alice<<endl;
        double sum=0;
        for(auto it:stoneValue)
            sum+=it;
        sum=sum/2;
        if((double)alice==sum)
            return "Tie";
        else if((double)alice>sum)
            return "Alice";
        return "Bob";
    }
};