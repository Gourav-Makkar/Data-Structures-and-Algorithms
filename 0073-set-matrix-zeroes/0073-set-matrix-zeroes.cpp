class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        int col=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    
                    if(j!=0)
                        mat[0][j]=0;
                    else
                        col=0;
                }
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=1;j--)
            {
                if(mat[i][0]==0 || mat[0][j]==0)
                    mat[i][j]=0;
            }
        }
        
        if(!col)
        {
            for(int i=0;i<n;i++)
                mat[i][0]=0;
        }
    }
};