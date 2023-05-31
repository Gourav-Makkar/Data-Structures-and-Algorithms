class Solution {
public:
    
    bool helper(int idx,int prev,string &s,unordered_set<string>&st,vector<vector<int>>&dp)
    {
        if(prev==s.size())
            return true;
        
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];
        
        for(int i=idx;i<s.size();i++)
        {
            string curr=s.substr(prev,i-prev+1);
            
            if(st.find(curr)!=st.end())
            {
                if(helper(i+1,i+1,s,st,dp))
                   return dp[idx][prev]=true;
            }
        }
        return dp[idx][prev]=false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st;
        for(auto it:wordDict)
            st.insert(it);
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,0,s,st,dp);
    }
};