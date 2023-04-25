class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        queue<vector<int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j,0});
                    mat[i][j]=-1;
                }
            }
        }
        
        while(!q.empty())
        {
            int cr=q.front()[0];
            int cc=q.front()[1];
            
            // cout<<cr<<" "<<cc<<endl;
            
            int dis=q.front()[2];
            q.pop();
            
            ans[cr][cc]=dis;
            
            vector<int>temp={-1,0,1,0,-1};
            
            for(int i=1;i<5;i++)
            {
                int nr=cr+temp[i-1];
                int nc=cc+temp[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]!=-1)
                {
                    q.push({nr,nc,dis+1});
                    mat[nr][nc]=-1;
                }
            }
        }
        return ans;
    }
};