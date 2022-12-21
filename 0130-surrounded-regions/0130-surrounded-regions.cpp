class Solution {
public:
    
    void bfs(vector<vector<char>>&board,int i,int j,int r,int c,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        
        while(!q.empty())
        {
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            
            if(cr>0 && vis[cr-1][cc]!=1 && board[cr-1][cc]=='O')
            {
                q.push({cr-1,cc});
                vis[cr-1][cc]=1;
            }
            
            if(cc<c-1 && vis[cr][cc+1]!=1 && board[cr][cc+1]=='O')
            {
                q.push({cr,cc+1});
                vis[cr][cc+1]=1;
            }
            
            if(cr<r-1 && vis[cr+1][cc]!=1 && board[cr+1][cc]=='O')
            {
                q.push({cr+1,cc});
                vis[cr+1][cc]=1;
            }
            
            if(cc>0 && vis[cr][cc-1]!=1 && board[cr][cc-1]=='O')
            {
                q.push({cr,cc-1});
                vis[cr][cc-1]=1;
            }
        }
    }
    
    void dfs(vector<vector<char>>&board,int i,int j,int r,int c,vector<vector<int>>&vis)
    {
        if(i<0 || i==r || j<0 || j==c || vis[i][j]==1 || board[i][j]!='O')
            return;
        
        vis[i][j]=1;
        
        dfs(board,i-1,j,r,c,vis);
        dfs(board,i,j+1,r,c,vis);
        dfs(board,i+1,j,r,c,vis);
        dfs(board,i,j-1,r,c,vis);
    }
    
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        
        vector<vector<int>>vis(r,vector<int>(c,0));
        
        for(int i=0;i<c;i++)
        {
            if(board[0][i]=='O')
                dfs(board,0,i,r,c,vis);
        }
        
        for(int i=0;i<r;i++)
        {
            if(board[i][c-1]=='O')
                dfs(board,i,c-1,r,c,vis);
        }
        
        for(int i=0;i<c;i++)
        {
            if(board[r-1][i]=='O')
                dfs(board,r-1,i,r,c,vis);
        }
        
        for(int i=0;i<r;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0,r,c,vis);
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(vis[i][j]!=1 && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};