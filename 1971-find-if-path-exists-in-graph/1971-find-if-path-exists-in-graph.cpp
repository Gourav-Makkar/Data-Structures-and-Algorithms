class Solution {
public:
    
    bool helper(int curr,vector<int>adj[],int des,vector<int>&vis)
    {
        if(curr==des)
            return true;
        if(vis[curr]==1)
            return false;
        vis[curr]=1;
        for(auto it:adj[curr])
        {
            if(helper(it,adj,des,vis))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return helper(source,adj,destination,vis);
    }
};