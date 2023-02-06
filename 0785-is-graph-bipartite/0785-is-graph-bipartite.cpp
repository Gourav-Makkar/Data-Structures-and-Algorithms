class Solution {
public:
    
    bool dfs(int curr,int clr,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[curr]=clr;
        
        for(auto it:adj[curr])
        {
            if(vis[it]==clr)
                return false;
            if(vis[it]==-1)
            {
                if(dfs(it,!clr,adj,vis)==false)
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(i,0,adj,vis)==false)
                    return false;
            }
        }
        return true;
    }
};