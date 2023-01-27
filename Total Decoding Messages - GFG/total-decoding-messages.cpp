//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod=1000000007;
	    int helper(string &s,int idx,vector<int>&dp)
	    {
	        int n=s.size();
	        if(idx>=n)
	          return 1;
	          
	        if(s[idx]=='0')
	          return 0;
	        
	        if(dp[idx]!=-1)
	          return dp[idx];
	        
	        int one=0,two=0;
	        
	        one=helper(s,idx+1,dp);
	        
	        if(idx!=n-1)
	        {
	            string temp="";
	            temp+=s[idx];
	            temp+=s[idx+1];
	            
	            int val=stoi(temp);
	            
	            if(val<=26)
	              two=helper(s,idx+2,dp);
	        }
	        
	        return dp[idx]=(one+two)%mod;
	    }
	     
		int CountWays(string str){
		   if(str[0]=='0')
		      return 0;
		    
		    vector<int>dp(str.size(),-1);
		    
		    return helper(str,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends