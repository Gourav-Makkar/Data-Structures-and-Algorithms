
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>m;
        
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(m.find(accounts[i][j])==m.end())
                {
                    m[accounts[i][j]]=i;
                }
                else
                    ds.UnionBySize(m[accounts[i][j]],i);
            }
        }
        vector<string>temp[n];
        vector<vector<string>>ans;
        
        for(auto it:m)
        {
            int up=ds.findUPar(it.second);
            temp[up].push_back(it.first);
        }
        
        for(int i=0;i<n;i++)
        {
            if(temp[i].size()!=0)
            {
                sort(temp[i].begin(),temp[i].end());
                vector<string>mails;
                mails.push_back(accounts[i][0]);
                
                for(auto it:temp[i])
                    mails.push_back(it);
                ans.push_back(mails);
            }
        }
        return ans;
    }
};