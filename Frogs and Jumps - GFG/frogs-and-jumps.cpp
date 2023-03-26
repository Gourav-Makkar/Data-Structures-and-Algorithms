//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        vector<int>vis(leaves+1,0);
        
        for(int i=0;i<n;i++)
        {
            int curr=frogs[i];
            if(curr>leaves)
              continue;
            
            if(!vis[curr])
            {
                 while(curr<=leaves)
                {
                    vis[curr]=1;
                    curr+=frogs[i];
                }
            }
        }
        int ans=0;
        for(auto it:vis)
        {
            if(it==0)
              ans++;
        }
        return ans-1;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends