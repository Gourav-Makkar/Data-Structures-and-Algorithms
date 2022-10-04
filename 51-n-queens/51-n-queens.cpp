class Solution {
public:
    
    bool isSafe(vector<string>board,int row,int col,int n)
    {
        //We have to check the 3 directions
        
        //upper left diagonal
        int r=row,c=col;
        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        
        c=col,r=row;
        while(c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            c--;
        }
         r=row,c=col;
        while(r<n && c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    
    void helper(vector<string>board,int col,int n,vector<vector<string>>&ans)
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
                helper(board,col+1,n,ans);
                board[r][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        helper(board,0,n,ans);
        
        return ans;
    }
};