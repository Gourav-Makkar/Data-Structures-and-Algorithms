class DisjointSet{
    vector<int>parent,size;
public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        // size.resize(n+1,1);

        for(int i=0;i<=n;i++)
          parent[i]=i;
    }
    int findUPar(int node)
    {
        if(parent[node]==node)
          return node;
        return parent[node]=findUPar(parent[node]);
    }

    void UnionBySize(int u,int v)
    {
        int pu=findUPar(u);
        int pv=findUPar(v);

        if(pu==pv)
          return;
        
        if(pu<pv)
        {
            parent[pv]=pu;
            // size[pv]+=size[pu];
        }
        else{
            parent[pu]=pv;
            // size[pu]+=size[pv];
        }

    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans="";
        int n=s1.size();
        
        DisjointSet ds(26);
        for(int i=0;i<n;i++)
        {
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            
            ds.UnionBySize(u,v);
        }
        
        for(auto it:baseStr)
        {
            int p=ds.findUPar(it-'a');
            ans+=(char)(p+97);
        }
        return ans;
    }
};