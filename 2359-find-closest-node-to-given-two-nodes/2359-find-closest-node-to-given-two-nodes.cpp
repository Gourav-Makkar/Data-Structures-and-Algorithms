class Solution {
public:
    
    void dfs(vector<int>adj[],int curr,vector<int>&dis,int d,vector<int>&vis)
    {
        vis[curr]=1;
        dis[curr]=d;
        for(auto it:adj[curr])
        {
            if(vis[it]==0)
                dfs(adj,it,dis,d+1,vis);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        vector<int>dis1(n,INT_MAX),dis2(n,INT_MAX);
        vector<int>vis(n,0);
        
        dfs(adj,node1,dis1,0,vis);
        
        for(int i=0;i<n;i++)
            vis[i]=0;
        
        dfs(adj,node2,dis2,0,vis);
        
        int mn=INT_MAX,ans=-1;
        for(int i=0;i<n;i++)
        {
            int d=max(dis1[i],dis2[i]);
            if(d<mn)
            {
                mn=d;
                ans=i;
            }
        }
        return ans;
    }
};