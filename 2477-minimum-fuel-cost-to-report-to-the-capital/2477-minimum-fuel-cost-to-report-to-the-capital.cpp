class Solution {
public:
    
    int dfs(int curr,int parent,vector<int>adj[],int seats,long long &ans)
    {
        int ct=0,rep=0;
        for(auto it:adj[curr])
        {
            if(it!=parent)
            {
                ct=dfs(it,curr,adj,seats,ans);
                rep+=ct;
                ans+=ceil(ct/(double)seats);
                // cout<<ans<<endl;
            }
        }
        
        return 1+rep;       
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int edges=roads.size();
        int n=edges+1;
        
        vector<int>adj[n+1];
        
        for(auto it:roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        long long ans=0;
        dfs(0,-1,adj,seats,ans);
        return ans;
    }
};