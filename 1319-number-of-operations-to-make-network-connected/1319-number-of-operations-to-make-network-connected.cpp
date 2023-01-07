#include<bits/stdc++.h>
using namespace std;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int tc=0,cc=0;
        
        for(auto it:connections)
        {
            if(ds.findUPar(it[0])==ds.findUPar(it[1]))
                tc++;
            else
                ds.UnionBySize(it[0],it[1]);
        }
        
        for(int i=0;i<n;i++)
        {
           if(ds.findUPar(i)==i)
               cc++;
              
        }
        if(cc-1>tc)
            return -1;
        return cc-1; 
    }
};