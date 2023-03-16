class Solution {
public:
    
    bool dfs(int curr,vector<vector<int>>&graph,vector<int>&vis,int clr)
    {
        vis[curr]=clr;
        
        for(auto it:graph[curr])
        {
            if(vis[it]!=-1)
            {
                if(vis[it]==clr)
                return false;
            }
            else
            {
                if(dfs(it,graph,vis,!clr)==false)
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>vis(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(i,graph,vis,0)==false)
                    return false;
            }
        }
        return true;
    }
};