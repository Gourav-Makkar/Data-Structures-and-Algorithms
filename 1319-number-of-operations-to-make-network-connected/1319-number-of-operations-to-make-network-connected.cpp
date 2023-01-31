class Solution {
public:
    
    void dfs(int curr,vector<int>adj[],vector<int>&vis)
    {
        vis[curr]=1;
        
        for(auto it:adj[curr])
        {
            if(vis[it]==0)
                dfs(it,adj,vis);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int>adj[n];
        
        if(con.size()<n-1)
            return -1;
        
        for(auto it:con)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                c++;
                dfs(i,adj,vis);
            }
        }
       
        return c-1;
    }
};