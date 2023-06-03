class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& inform) {
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        
        int ans=0;
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
                q.push({it,time+inform[curr]});
            }
        }
        return ans;
    }
};