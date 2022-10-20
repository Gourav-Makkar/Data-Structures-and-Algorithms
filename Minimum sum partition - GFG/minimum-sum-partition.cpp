//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	  
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
                nums[i]=-nums[i];
            sum+=nums[i];
        }
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=sum)
            dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool nt=dp[i-1][target];
                bool t=false;
                if(nums[i]<=target)
                   t=dp[i-1][target-nums[i]];
                
                dp[i][target]= nt||t;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=sum;i++)
        {
            if(dp[n-1][i]==true)
            {
                int s1=i;
                int s2=sum-s1;
                ans=min(ans,abs(s2-s1));
            }
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends