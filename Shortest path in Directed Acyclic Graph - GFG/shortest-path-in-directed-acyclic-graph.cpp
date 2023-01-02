//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void dfs(int curr,vector<pair<int,int>>adj[],vector<int>&vis,stack<int>&st)
     {
         vis[curr]=1;
         
         for(auto it:adj[curr])
         {
             if(vis[it.first]!=1)
               dfs(it.first,adj,vis,st);
         }
         st.push(curr);
     }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>vis(N,0),dis(N,1e9);
        
        stack<int>st;
        
        for(int i=0;i<N;i++)
        {
            if(vis[i]!=1)
              dfs(i,adj,vis,st);
        }
        
        dis[0]=0;
        
        while(!st.empty())
        {
            int curr=st.top();
            st.pop();
            int d=dis[curr];
            
            for(auto it:adj[curr])
            {
                int node=it.first;
                int x=it.second;
                
                if(d+x<dis[node])
                  dis[node]=d+x;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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