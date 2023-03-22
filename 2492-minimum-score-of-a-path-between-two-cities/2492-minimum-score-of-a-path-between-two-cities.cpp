class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>dis(n+1,INT_MAX);
        vector<pair<int,int>>adj[n+1];
        
        for(auto it:roads)
        {
            int u=it[0],v=it[1],d=it[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        
        queue<int>q;
        q.push(1);
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            
            
            for(auto it:adj[curr])
            {
                if(it.second<dis[it.first])
                {
                    dis[it.first]=it.second;
                    q.push(it.first);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
            ans=min(ans,dis[i]);
        return ans;
    }
};