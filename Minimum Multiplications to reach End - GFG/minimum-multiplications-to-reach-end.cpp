//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=100000;
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int>dis(100001,INT_MAX);
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(curr==end)
              return steps;

            for(auto it:arr)
            {
                int n=(curr*it)%mod;
                if(dis[n]==INT_MAX)
                 {
                      q.push({n,steps+1});
                      dis[n]=steps+1;
                 }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends