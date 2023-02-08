class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int start=1,mxLength=1;
        
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=1;
            
            if(i!=n && s[i-1]==s[i])
            {
                dp[i][i+1]=1;
                start=i;
                mxLength=2;
            }
        }
        
        for(int length=3;length<=n;length++)
        {
            for(int i=1;i<=n-length+1;i++)
            {
                int j=i+length-1;
                if(s[i-1]==s[j-1])
                    dp[i][j]=dp[i+1][j-1];
                else
                    dp[i][j]=0;
                
                if(dp[i][j]==1)
                {
                    start=i;
                    mxLength=length;
                }
            }
        }
        string ans;
        int st=start-1,en=start+mxLength-1;
        
        for(int i=st;i<en;i++)
            ans+=s[i];
        return ans;
    }
};