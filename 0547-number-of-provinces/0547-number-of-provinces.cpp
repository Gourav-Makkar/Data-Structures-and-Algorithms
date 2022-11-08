class Solution {
public:
    
    void dfs(vector<vector<int>>& v,vector<int>&vis,int node)
    {
        vis[node]=1;
        for(int i=0;i<v.size();i++)
        {
            if(vis[i+1]!=1  && v[node-1][i]==1)
                dfs(v,vis,i+1);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>vis(v+1,0);
        int ct=0;
        for(int i=1;i<v+1;i++)
        {
            if(!vis[i])
            {
                ct++;
                dfs(isConnected,vis,i);
            }
        }
        return ct;
    }
};