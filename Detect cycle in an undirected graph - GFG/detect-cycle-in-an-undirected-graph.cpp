//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool detectBfs(int src,vector<int>adj[],vector<int>&vis)
    {
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adj[curr])
            {
                if(it!=parent)
                {
                    if(vis[it]!=1)
                     {
                         q.push({it,curr});
                         vis[it]=1;
                     }
                     else
                       return true;
                }
            }
        }
        return false;
    }
    
    
    bool detectDfs(int src,int parent,vector<int>adj[],vector<int>&vis)
    {
        vis[src]=1;
        
        for(auto curr:adj[src])
        {
            if(curr!=parent)
            {
                if(vis[curr]!=1)
                {
                    if(detectDfs(curr,src,adj,vis))
                      return true;
                }
                
                else
                  return true;
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]!=1)
            {
                 if(detectDfs(i,-1,adj,vis))
                   return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends