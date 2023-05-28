class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                    vis[i][j]=1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j])
                {
                    for(int r=0;r<n;r++)
                        mat[r][j]=0;
                    
                    for(int c=0;c<m;c++)
                        mat[i][c]=0;
                }
            }
        }
        
    }
};