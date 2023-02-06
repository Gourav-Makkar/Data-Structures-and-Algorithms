//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n,1e9);
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i+j>=n)
                  break;
                dp[i+j]=min(dp[i+j],dp[i]+abs(height[i]-height[i+j]));
            }
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends