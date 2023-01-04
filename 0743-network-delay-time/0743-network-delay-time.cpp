class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adj[n+1];
        for(auto it:times)
          adj[it[0]].push_back({it[1],it[2]});
        
        vector<int>time(n+1,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,k});
        time[k]=0;
        
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();
            int t=p.first;
            int node=p.second;
            
            for(auto it:adj[node])
            {
                if(t+it[1]<time[it[0]])
                {
                    time[it[0]]=t+it[1];
                    pq.push({time[it[0]],it[0]});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
            ans=max(ans,time[i]);
        
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};