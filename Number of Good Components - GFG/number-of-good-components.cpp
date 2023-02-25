//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int curr,vector<vector<int>>&adj,vector<int>&vis,vector<int>&cc)
    {
        vis[curr]=1;
        cc.push_back(curr);
        
        for(auto it:adj[curr])
        {
            if(!vis[it])
              dfs(it,adj,vis,cc);
        }
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<int>vis(V+1,0);
        vector<vector<int>>tc;
        
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                vector<int>cc;
                dfs(i,adj,vis,cc);
                tc.push_back(cc);
            }
        }
        
        // for(auto it:tc)
        // {
        //     for(int i=0;i<it.size();i++)
        //       cout<<it[i]<<" ";
        //     cout<<endl;
        // }
        
        // cout<<tc.size()<<endl;
        
        int ans=0;
        for(auto it:tc)
        {
            int n=it.size();
            bool flag=true;
            for(int i=0;i<it.size();i++)
            {
                if(adj[it[i]].size()!=(n-1))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
              ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends