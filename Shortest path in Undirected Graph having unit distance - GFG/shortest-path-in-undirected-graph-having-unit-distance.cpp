//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>dis(N,1e9);
        vector<int>vis(N,0);
        
        vector<int>adj[N];
        
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src]=0;
        vis[src]=1;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(vis[it]==0)
                {
                    dis[it]=d+1;
                    q.push({it,dis[it]});
                    vis[it]=1;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dis[i]==1e9)
              dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends