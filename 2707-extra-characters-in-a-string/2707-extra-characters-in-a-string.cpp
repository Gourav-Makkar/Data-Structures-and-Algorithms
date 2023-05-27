class Solution {
public:
    
    int helper(int idx,string &s,unordered_map<string,int>&m,vector<int>&dp)
    {
       if(idx==s.size())
           return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans=1e9;
        
        for(int i=1;idx+i<=s.size();i++)
        {
            string temp=s.substr(idx,i);
            
            if(m.find(temp)!=m.end())
            {
               ans=min(ans,0+helper(idx+i,s,m,dp));
            }
            ans=min(ans,i + helper(idx+i,s,m,dp));
        }
        return dp[idx]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>m;
        vector<int>dp(s.size(),-1);
     
        for(auto it:dictionary)
            m[it]++;
        
        return helper(0,s,m,dp);
    }
};