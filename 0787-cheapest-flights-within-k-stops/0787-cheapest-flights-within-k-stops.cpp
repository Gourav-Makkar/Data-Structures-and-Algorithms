class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>cost(n,INT_MAX);
        cost[src]=0;
        
        vector<vector<int>>adj[n];
        for(auto it:flights)
            adj[it[0]].push_back({it[1],it[2]});
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{src,0}});
        
        while(!pq.empty())
        {
            pair<int,pair<int,int>>p=pq.front();
            pq.pop();
            
            int cc=p.first;
            int node=p.second.first;
            int stops=p.second.second;
            
            if(stops>k)
                continue;
            
            for(auto it:adj[node])
            {
                if(cc+it[1]<cost[it[0]])
                {
                    cost[it[0]]=cc+it[1];
                    pq.push({cost[it[0]],{it[0],stops+1}});
                }
            }
        }
        if(cost[dst]==INT_MAX)
            return -1;
        return cost[dst];
    }
};