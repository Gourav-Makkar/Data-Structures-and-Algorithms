class Solution {
public:
    
    int findPar(int curr,vector<int>&par)
    {
        if(curr==par[curr])
            return curr;
        
        return par[curr]=findPar(par[curr],par);
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>par(n+1);
        vector<int>dis(n+1,INT_MAX);
        
        for(int i=1;i<=n;i++)
            par[i]=i;
        
        for(auto it:roads)
        {
            int u=it[0],v=it[1],d=it[2];
            
            int pu=findPar(u,par);
            int pv=findPar(v,par);
            
            if(pu==1 || pv==1)
            {
                dis[1]=min(dis[1],d);
                if(pu==1)
                {
                    // size[pu]+=size[pv];
                    par[pv]=pu;
                }
                if(pv==1)
                {
                    // size[pv]+=size[pu];
                    par[pu]=pv;
                }
            }
            else
            {
                dis[pu]=min(dis[pu],d);
                dis[pv]=min(dis[pv],d);
                
                // if(size[pu]<size[pv])
                // {
                //     size[pv]+=size[pu];
                //     par[pu]=pv;
                // }
                // else
                // {
                //     size[pu]+=size[pv];
                //     par[pv]=pu;
                // }
                par[pu]=pv;
            }
        }
        
        for(auto it:roads)
        {
            int u=it[0],v=it[1],d=it[2];
            
            int pu=findPar(u,par);
            int pv=findPar(v,par);
            
            if(pu==1 || pv==1)
                dis[1]=min(dis[1],d);
        }
        
        return dis[1];
    }
};