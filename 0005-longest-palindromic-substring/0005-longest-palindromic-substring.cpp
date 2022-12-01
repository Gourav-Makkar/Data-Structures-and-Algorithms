class Solution {
public:
    string longestPalindrome(string s) {
        string a=s;
        int n=s.size();
        reverse(a.begin(),a.end());
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        int maxLength=0, start=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==a[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    int rIdx=i;
                    int idx=j-dp[i][j]+1;
                    if(n-rIdx+1==idx){     //Here we check if the reverse string original idx is same as original string idx.
                        if(maxLength<dp[i][j]){ 
                            maxLength=dp[i][j];
                            start=i;
                        }
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        string res;
        while(maxLength>0){
            res.push_back(s[start-1]);
            start--;
            maxLength--;
        }
        return res;
    }
};