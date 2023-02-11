class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<pair<int,int>>adj[n];
        map<pair<int,int>,int>vis;
        
        for(auto it:red)
        {
            vis[{it[1],1}]=0;
            adj[it[0]].push_back({it[1],1});
        } 
      
        for(auto it:blue)
        {
            vis[{it[1],2}]=0;
            adj[it[0]].push_back({it[1],2});
        }  
        
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{-1,0}}); // {curr node,{parent color,curr dis}}
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int parent=q.front().second.first;
            int d=q.front().second.second;
            
            q.pop();
            
            for(auto it:adj[curr])
            {
                int nxt=it.first;
                int clr=it.second;
                
                if(clr!=parent && vis[{nxt,clr}]==0)
                {
                    q.push({nxt,{clr,d+1}});
                    vis[{nxt,clr}]=1;
                    
                    if(dis[nxt]>d+1)
                        dis[nxt]=d+1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dis[i]==INT_MAX)
                dis[i]=-1;
        }
        return dis;
    }
};