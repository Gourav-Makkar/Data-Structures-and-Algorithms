class Solution {
public:
    
    void dfs(int curr,vector<int>adj[],vector<int>&vis,int &ct)
    {
        vis[curr]=1;
        ct++;
        
        for(auto it:adj[curr])
        {
            if(!vis[it])
                dfs(it,adj,vis,ct);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>sizes,vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int ct=0;
                dfs(i,adj,vis,ct);
                sizes.push_back(ct);
            }
        }
        long long total=0,ans=0;
        for(auto it:sizes)
            total+=it;
        
        for(auto it:sizes)
        {
            total-=it;
            ans+=total*it;
        }
        return ans;
    }
};