class Solution {
public:
    
//     void dfs(int curr,vector<int>adj[],vector<int>&vis,int &ct)
//     {
//         vis[curr]=1;
//         ct++;
        
//         for(auto it:adj[curr])
//         {
//             if(!vis[it])
//                 dfs(it,adj,vis,ct);
//         }
//     }
    int findPar(int curr,vector<int>&par)
    {
        if(par[curr]==curr)
            return curr;
        return par[curr]=findPar(par[curr],par);
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>par(n),size(n,1);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(auto it:edges)
        {
            int pu=findPar(it[0],par);
            int pv=findPar(it[1],par);
            
            if(pu==pv)
                continue;
            if(size[pu]<size[pv])
            {
                size[pv]+=size[pu];
                size[pu]=0;
                par[pu]=pv;
            }
            else
            {
                size[pu]+=size[pv];
                size[pv]=0;
                par[pv]=pu;
            }
        }
        vector<int>temp;
        long long total=0,ans=0;
        
        for(auto it:size)
        {
            if(it>0)
            {
                temp.push_back(it);
                total+=it;
            }
        }
        
        for(auto it:temp)
        {
            total-=it;
            ans+=it*total;
        }
        return ans;
    }
};