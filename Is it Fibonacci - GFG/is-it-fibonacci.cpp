//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    // long long helper(int n,int k,vector<long long>&nums)
    // {
    //     if(n<=k)
    //       return nums[n-1];
          
    //     long long ans=0;
    //     for(int i=n-k;i<n;i++)
    //       ans+=helper(i,k,nums);
    //     return ans;
    // }
  
    long long solve(int n, int k, vector<long long> GeekNum) {
        
        if(n<=k)
          return GeekNum[n-1];
        
        vector<long long>ans;
        
        for(auto it:GeekNum)
          ans.push_back(it);
          
        for(int i=k;i<n;i++)
        {
            long long temp=0;
            for(int j=i-k;j<i;j++)
              temp+=ans[j];
              
            ans.push_back(temp);
        }
        return ans.back();
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends