#define ll long long
class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ll>>adj[n];
        int mod=1e9+7;
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        vector<ll>time(n,LONG_MAX);
        vector<ll>ways(n,0);
        
        time[0]=0;
        ways[0]=1;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            ll t=pq.top().first;
            ll node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                if(t+it[1]<time[it[0]])
                {
                    time[it[0]]=t+it[1];
                    ways[it[0]]=ways[node]  ;
                    pq.push({time[it[0]],it[0]});
                }
                else if(t+it[1]==time[it[0]])
                  ways[it[0]]=(ways[it[0]]+ways[node])%mod;
            }
        }
        
        return ways[n-1]%mod;
    }
};