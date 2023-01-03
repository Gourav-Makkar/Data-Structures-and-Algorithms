class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<int>>ef(r,vector<int>(c,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        ef[0][0]=0;
        
        while(!pq.empty())
        {
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            
            int cr=p.second.first;
            int cc=p.second.second;
            int e=p.first;
            
            if(cr>0)
            {
                int ce=abs(grid[cr][cc]-grid[cr-1][cc]);
                ce=max(ce,e);
                if(ce<ef[cr-1][cc])
                {
                    ef[cr-1][cc]=ce;
                    pq.push({ce,{cr-1,cc}});
                }
            }
            if(cc<c-1)
            {
                int ce=abs(grid[cr][cc]-grid[cr][cc+1]);
                ce=max(ce,e);
                if(ce<ef[cr][cc+1])
                {
                    ef[cr][cc+1]=ce;
                    pq.push({ce,{cr,cc+1}});
                }
            }
            if(cr<r-1)
            {
                int ce=abs(grid[cr][cc]-grid[cr+1][cc]);
                ce=max(ce,e);
                if(ce<ef[cr+1][cc])
                {
                    ef[cr+1][cc]=ce;
                    pq.push({ce,{cr+1,cc}});
                }
            }
            if(cc>0)
            {
                int ce=abs(grid[cr][cc]-grid[cr][cc-1]);
                ce=max(ce,e);
                if(ce<ef[cr][cc-1])
                {
                    ef[cr][cc-1]=ce;
                    pq.push({ce,{cr,cc-1}});
                }
            }
        }
        
        return ef[r-1][c-1];
    }
};