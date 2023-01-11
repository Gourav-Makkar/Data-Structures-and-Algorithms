class Solution {
public:
    
    int dfs(int node,int parent,vector<int>adj[],vector<bool>&hasApple)
    {
        int time=0,ct=0;
        
        for(auto it:adj[node])
        {
            if(it!=parent)
            {
                ct=dfs(it,node,adj,hasApple);
                
                if(ct>0 || hasApple[it])
                    time+= (ct+2);
            }
        }
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans=0;
        vector<int>adj[n];
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return dfs(0,-1,adj,hasApple);
    }
};