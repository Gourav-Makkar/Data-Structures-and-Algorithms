class Solution {
public:
    int mod=1000000007;
    int helper(int idx,string &s,int k,vector<int>&dp)
    {
        int n=s.size();
        if(idx>=n)
            return 1;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans=0;
        for(int i=1;i<=n-idx;i++)
        {
            string temp=s.substr(idx,i);
            if(temp.size()>9)
                break;
            int val=stoi(temp);
            
            if(val==0)
                return dp[idx]=0;
            
            if(val<=k)
                ans=(ans+helper(idx+i,s,k,dp))%mod;
        }
        return dp[idx]=ans;
    }
    
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.size(),-1);
        return helper(0,s,k,dp);
    }
};