class Solution {
public:
    
    void dfs(vector<int>adj[],vector<int>&vis,int curr)
    {
        vis[curr]=1;
        for(auto it:adj[curr])
        {
            if(vis[it]!=1)
                dfs(adj,vis,it);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                    adj[i].push_back(j);
            }
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                ans++;
                dfs(adj,vis,i);
            }
        }
        return ans;
    }
};