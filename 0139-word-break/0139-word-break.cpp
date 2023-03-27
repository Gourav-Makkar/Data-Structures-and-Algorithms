class Solution {
public:
    
    bool helper(int idx,string &s,int prev,unordered_set<string>&st,vector<vector<int>>&dp)
    {
        int n=s.size();
        
        if(idx==n)
        {
            if(prev==n)
                return true;
            return false;
        }
        
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];
        
        string curr=s.substr(prev,idx-prev+1);
        bool take=false;
        
        if(st.find(curr)!=st.end())
          take=helper(idx+1,s,idx+1,st,dp);
        
        bool nottake=helper(idx+1,s,prev,st,dp);
        
        return dp[idx][prev]=take||nottake;  
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st;
        for(auto it:wordDict)
            st.insert(it);
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return helper(0,s,0,st,dp);
    }
};