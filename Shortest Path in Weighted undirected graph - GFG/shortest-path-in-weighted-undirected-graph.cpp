//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>dis(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++)
          parent[i]=i;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        dis[1]=0;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                if(d+it[1]<dis[it[0]])
                {
                    dis[it[0]]=d+it[1];
                    pq.push({dis[it[0]],it[0]});
                    parent[it[0]]=node;
                }
            }
        }
        vector<int>ans;
        if(dis[n]==1e9)
          return {-1};
        
        ans.push_back(n);
        int curr=n;
        while(curr!=1)
        {
            int node=parent[curr];
            ans.push_back(node);
            curr=node;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends