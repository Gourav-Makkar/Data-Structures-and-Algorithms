class Solution {
public:
    
    bool helper(int idx1,int idx2,string &s,string &p,vector<vector<int>>&dp)
    {
        if(idx1==0 && idx2==0)
            return true;
        
        if(idx2==0)
            return false;
        
        if(idx1==0)
        {
            for(int i=idx2;i>0;i--)
            {
                if(p[i-1]!='*')
                    return false;
            }
            return true;
        }
    
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(s[idx1-1]==p[idx2-1] || p[idx2-1]=='?')
            return dp[idx1][idx2]=helper(idx1-1,idx2-1,s,p,dp);
        
        if(p[idx2-1]=='*')
        {
            bool first=helper(idx1-1,idx2,s,p,dp);
            bool second=helper(idx1,idx2-1,s,p,dp);
            
            return dp[idx1][idx2]=first||second;
        }
        return dp[idx1][idx2]=false;
}
    
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return helper(n1,n2,s,p,dp);
    }
};