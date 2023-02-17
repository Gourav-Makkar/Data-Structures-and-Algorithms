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
        
        long long sum=0;
        int i=0,j=0;
        
        while(j<n-1)
        {
            sum+=ans[j];
            
            if(j-i+1==k)
            {
                ans.push_back(sum);
                sum-=ans[i];
                i++;
            }
            j++;
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