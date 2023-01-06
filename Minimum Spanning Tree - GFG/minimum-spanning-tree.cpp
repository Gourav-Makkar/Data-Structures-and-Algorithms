//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
      
        vector<int>vis(V,0);
        pq.push({0,0,-1});
        
        while(!pq.empty())
        {
            int wt=pq.top()[0];
            int node=pq.top()[1];
            int parent=pq.top()[2];
            
            pq.pop();
            if(vis[node]==1)
              continue;
            vis[node]=1;
            
            sum+=wt;
            
            for(auto it:adj[node])
            {
                if(vis[it[0]]!=1)
                {
                    pq.push({it[1],it[0],node});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends