class Solution {
public:
    void dfs(int cr,int cc,vector<vector<int>>&mat,vector<vector<int>>&vis,int n,int m)
    {
        if(vis[cr][cc])
          return;
        vis[cr][cc]=1;
        
        if(cr>0 && mat[cr-1][cc]>=mat[cr][cc])
          dfs(cr-1,cc,mat,vis,n,m);
          
        if(cc<m-1 && mat[cr][cc+1]>=mat[cr][cc])
          dfs(cr,cc+1,mat,vis,n,m);
        
        if(cr<n-1 && mat[cr+1][cc]>=mat[cr][cc])
          dfs(cr+1,cc,mat,vis,n,m);
        
        if(cc>0 && mat[cr][cc-1]>=mat[cr][cc])
          dfs(cr,cc-1,mat,vis,n,m);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int n=heights.size();
       int m=heights[0].size();
       vector<vector<int>>pac(n,vector<int>(m,0));
       vector<vector<int>>atl(n,vector<int>(m,0));
       
       for(int i=0;i<n;i++)
       {
           dfs(i,0,heights,pac,n,m);
           dfs(i,m-1,heights,atl,n,m);
       }
       
       for(int i=0;i<m;i++)
       {
           dfs(0,i,heights,pac,n,m);
           dfs(n-1,i,heights,atl,n,m);
       }
       vector<vector<int>>ans;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(pac[i][j]==1 && atl[i][j]==1)
                 ans.push_back({i,j});
           }
       }
       return ans;
    }
};