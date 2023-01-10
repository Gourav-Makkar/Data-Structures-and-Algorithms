class Solution {
public:
    
    bool isSafe(vector<string>&board,int r,int c,int n)
    {
        //upper left diagonal
        
        int cr=r-1,cc=c-1;
        while(cr>=0 && cc>=0)
        {
            if(board[cr][cc]=='Q')
                return false;
            cr--;
            cc--;
        }
        
        //left cols
        cc=c-1;
        while(cc>=0)
        {
            if(board[r][cc]=='Q')
                return false;
            cc--;
        }
        
        //bottom left diagonal
        cr=r+1,cc=c-1;
        while(cr<n && cc>=0)
        {
            if(board[cr][cc]=='Q')
                return false;
            cr++;
            cc--;
        }
       return true;
    }
    
    void helper(int col,vector<string>&board,int n,vector<vector<string>>&ans)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++)
        {
            if(isSafe(board,r,col,n))
            {
                board[r][col]='Q';
                helper(col+1,board,n,ans);
                board[r][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        
        vector<string>board;
        for(int i=0;i<n;i++)
        {
            string curr="";
            for(int i=0;i<n;i++)
            {
                curr+='.';
            }
            board.push_back(curr);
        }
        
        helper(0,board,n,ans);
        return ans;
        
    }
};