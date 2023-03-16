class Solution {
public:
    
    
    void dfs(int curr,vector<int>adj[],vector<int>&vis)
    {
        vis[curr]=1;
        
        for(auto it:adj[curr])
        {
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};