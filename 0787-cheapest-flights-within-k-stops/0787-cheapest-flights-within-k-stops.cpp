class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>cost(n,INT_MAX);
        cost[src]=0;
        
        vector<vector<int>>adj[n];
        for(auto it:flights)
            adj[it[0]].push_back({it[1],it[2]});
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        
        while(!pq.empty())
        {
            vector<int>p=pq.top();
            pq.pop();
            
            int stops=p[0];
            int node=p[1];
            int cc=p[2];
            
            if(stops>k)
                continue;
            
            for(auto it:adj[node])
            {
                if(cc+it[1]<cost[it[0]])
                {
                    cost[it[0]]=cc+it[1];
                    pq.push({stops+1,it[0],cost[it[0]]});
                }
            }
        }
        if(cost[dst]==INT_MAX)
            return -1;
        return cost[dst];
    }
};