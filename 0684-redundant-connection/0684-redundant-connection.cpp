
class DisjointSet{
    vector<int>parent,rank,size;
public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++)
          parent[i]=i;
    }
    int findUPar(int node)
    {
        if(parent[node]==node)
          return node;
        return parent[node]=findUPar(parent[node]);
    }

    void UnionByRank(int u,int v)
    {
        int pu=findUPar(u);
        int pv=findUPar(v);

        if(pu==pv)
          return;
        
        if(rank[pu]<rank[pv])
          parent[pu]=pv;
        else if(rank[pv]<rank[pu])
          parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }

    }
    void UnionBySize(int u,int v)
    {
        int pu=findUPar(u);
        int pv=findUPar(v);

        if(pu==pv)
          return;
        
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }

    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int st,en;
        
        int n=edges.size();
        DisjointSet ds(n);
        
        for(auto it:edges)
        {
            if(ds.findUPar(it[0]) == ds.findUPar(it[1]))
            {
                st=it[0];
                en=it[1];
            }
            else
                ds.UnionBySize(it[0],it[1]);
        }
        
        return {st,en};
    }
};