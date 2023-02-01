class DisjointSet{
    vector<int>parent,size;
public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        
        for(int i=0;i<equations.size();i++)
        {
            string s=equations[i];
            if(s[1]=='=')
                ds.UnionBySize(s[0]-'a',s[3]-'a');
        }
        for(int i=0;i<equations.size();i++)
        {
            string s=equations[i];
            if(s[1]=='!')
            {
                int pu=ds.findUPar(s[0]-'a');
                int pv=ds.findUPar(s[3]-'a');
                
                if(pu==pv)
                    return false;
            }
        }
        return true;
    }
};