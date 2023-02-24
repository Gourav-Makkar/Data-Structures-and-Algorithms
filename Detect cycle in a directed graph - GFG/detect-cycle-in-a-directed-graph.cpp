//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int curr,vector<int>adj[],vector<int>&vis,vector<int>&pathVis)
    {
        vis[curr]=1;
        pathVis[curr]=1;
        
        for(auto it:adj[curr])
        {
            if(vis[it]!=1)
            {
                if(dfs(it,adj,vis,pathVis))
                  return true;
            }
            else
            {
                if(pathVis[it]==1)
                  return true;
            }
        }
        pathVis[curr]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0),pathVis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]!=1)
            {
                if(dfs(i,adj,vis,pathVis))
                   return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends