class Solution {
public:
    
    int helper(int curr,int parent,vector<int>adj[],vector<bool>&apple)
    {
        int ans=1;
        for(auto it:adj[curr])
        {
            if(it!=parent)
            {
                int ct=helper(it,curr,adj,apple);
                
                if(ct>0)
                    ans+=ct;
            }
        }
        
        if(!apple[curr] && ans==1)
            return 0;
        return ans;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
       int nodes=helper(0,-1,adj,hasApple);
       if(nodes==0)
            return 0;
       return 2*(nodes-1);
    }
};