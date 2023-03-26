class Solution {
public:
    
    void dfs(int curr,vector<int>&edges,vector<int>&vis,vector<int>&pathvis,int &ans)
    {
        vis[curr]=1;
        pathvis[curr]=1;
        
        int adj=edges[curr];
        if(adj==-1)
        {
            pathvis[curr]=0;
            return;
        }
        if(!vis[adj])
            dfs(adj,edges,vis,pathvis,ans);
        
        if(pathvis[adj])
        {
            int node=adj;
            int len=0;
            do{
                len++;
                node=edges[node];
            }while(node!=adj);
            ans=max(ans,len);
        }
       pathvis[curr]=0; 
    }
    
    int longestCycle(vector<int>& edges) {
        int ans=-1;
        int n=edges.size();
        
        vector<int>vis(n,0),pathvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,edges,vis,pathvis,ans);
            }
        }
        return ans;
    }
};