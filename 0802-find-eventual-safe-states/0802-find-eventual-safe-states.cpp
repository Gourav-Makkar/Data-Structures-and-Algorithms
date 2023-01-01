class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,int curr,vector<int>&vis,vector<int>&pathvis,vector<int>&ans)
    {
        vis[curr]=1;
        pathvis[curr]=1;
        
        for(auto it:graph[curr])
        {
            if(pathvis[it]==1)
              return true;
              
            if(vis[it]==0 && dfs(graph,it,vis,pathvis,ans))
               return true;
        }
        ans.push_back(curr);
        pathvis[curr]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
                dfs(graph,i,vis,pathvis,ans);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};