class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>price(n,INT_MAX);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0,{0,src}});
        price[src]=0;
        while(!pq.empty())
        {
            int stops=pq.top().first;
            int cost=pq.top().second.first;
            int curr=pq.top().second.second;

            pq.pop();
            
            if(stops>k)
                break;
            if(curr==dst)
                continue;
            for(auto it:adj[curr])
            {
                if(cost+it.second<price[it.first])
                {
                    price[it.first]=cost+it.second;
                    pq.push({stops+1,{price[it.first],it.first}});
                }
            }
        }
        if(price[dst]==INT_MAX)
            return -1;
        return price[dst];
    }
};