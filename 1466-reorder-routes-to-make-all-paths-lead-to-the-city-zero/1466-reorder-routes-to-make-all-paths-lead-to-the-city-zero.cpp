class Solution {
public:
    
    void dfs(int curr,vector<int>adj[],set<pair<int,int>>&s,int &ans,vector<int>&vis)
    {
        vis[curr]=1;
        for(auto it:adj[curr])
        {
            if(!vis[it])
            {
                if(s.find({curr,it})!=s.end())
                  ans++;
                dfs(it,adj,s,ans,vis);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int,int>>s;
        vector<int>adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
            s.insert({it[0],it[1]});
        }
        
        int ans=0;
        vector<int>vis(n,0);
        dfs(0,adj,s,ans,vis);
        return ans;
    }
};