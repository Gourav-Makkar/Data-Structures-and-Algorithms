class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& inform) {
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                adj[i].push_back(manager[i]);
                adj[manager[i]].push_back(i);
            }
        }
        
        int ans=0;
        vector<int>vis(n,0);
        vis[headId]=1;
        queue<pair<int,int>>q;
        q.push({headId,0});
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int time=q.front().second;
            
            q.pop();
            
            ans=max(ans,time);
            for(auto it:adj[curr])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,time+inform[curr]});
                }
            }
        }
        return ans;
    }
};