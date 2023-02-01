class Solution {
public:
    
    int findPar(int x,vector<int>&par)
    {
        if(par[x]==x)
            return x;
        return par[x]=findPar(par[x],par);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>par(n+1);
        for(int i=1;i<=n;i++)
            par[i]=i;
        
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            
            int pu=findPar(u,par);
            int pv=findPar(v,par);
            
            if(pu==pv)
                return {u,v};
            
            par[pu]=par[pv];
        }
        return {-1,-1};
    }
};