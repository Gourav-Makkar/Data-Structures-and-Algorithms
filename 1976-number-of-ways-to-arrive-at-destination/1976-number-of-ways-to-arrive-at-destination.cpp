#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        int mod=1000000007,ans=0;
        ll mn=INT_MAX;
        
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<ll>time(n,LONG_MAX);
        time[0]=0;
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        vector<int>ways(n,0);
        ways[0]=1;
        
        while(!pq.empty())
        {
            ll curr=pq.top().second;
            ll t=pq.top().first;
            pq.pop();
            
            for(auto it:adj[curr])
            {
                ll node=it.first,dis=it.second;
                if(t+dis<time[node])
                {
                    time[node]=t+dis;
                    ways[node]=ways[curr];
                    pq.push({time[node],node});
                }
                else if(t+dis==time[node])
                    ways[node]=(ways[node]+ways[curr])%mod;
            }
        }
        return ways[n-1];
    }
};