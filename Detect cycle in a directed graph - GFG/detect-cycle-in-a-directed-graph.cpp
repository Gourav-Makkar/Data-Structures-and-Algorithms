//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
   bool dfs(int curr,vector<int>adj[],vector<int>&vis,vector<int>&pathvis)
    {
        vis[curr]=1;
        pathvis[curr]=1;
        
        for(auto it:adj[curr])
        {
            if(pathvis[it]==1)
              return true;
              
            if(vis[it]==0 && dfs(it,adj,vis,pathvis))
               return true;
        }
        pathvis[curr]=0;
        return false;
    }
    
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathvis))
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