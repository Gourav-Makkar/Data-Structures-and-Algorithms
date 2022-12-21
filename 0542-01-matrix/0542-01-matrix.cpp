class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        
        vector<vector<int>>ans(r,vector<int>(c));
        vector<vector<int>>vis(r,vector<int>(c,0));
         
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty())
        {
            int cr=q.front().first.first;
            int cc=q.front().first.second;
            
            int dis=q.front().second;
            q.pop();
            ans[cr][cc]=dis;
            
            if(cr>0 && vis[cr-1][cc]!=1)
            {
                q.push({{cr-1,cc},dis+1});
                vis[cr-1][cc]=1;
            }
            
            if(cc<c-1 && vis[cr][cc+1]!=1)
            {
                q.push({{cr,cc+1},dis+1});
                vis[cr][cc+1]=1;
            }
            
            if(cr<r-1 && vis[cr+1][cc]!=1)
            {
                 q.push({{cr+1,cc},dis+1});
                 vis[cr+1][cc]=1;
            }
            
            if(cc>0 && vis[cr][cc-1]!=1)
            {
                q.push({{cr,cc-1},dis+1});
                vis[cr][cc-1]=1;
            }
        }
        
        return ans;
        
    }
};