class Solution {
public:
    
    int findPar(int curr,vector<int>par)
    {
        if(par[curr]==curr)
            return curr;
        
        return par[curr]=findPar(par[curr],par);
    }
    
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        
        vector<int>par(n),size(n,1);
        
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j])
                {
                    int pi=findPar(i,par);
                    int pj=findPar(j,par);
                    
                    if(pi==pj)
                        continue;
                    
                    if(size[pi]<size[pj])
                    {
                        size[pj]+=size[pi];
                        par[pi]=pj;
                    }
                    
                    else
                    {
                        size[pi]+=size[pj];
                        par[pj]=pi;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
                ans++;
        }
        return ans;
    }
};