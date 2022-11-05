class Solution {
public:
    
    bool helper(vector<vector<char>>&board,int cr,int cc,int r,int c,string word,int idx)
    {
        if(idx==word.size())
            return true;
        if(cr<0 || cr==r || cc<0 || cc==c || board[cr][cc]=='-1' || board[cr][cc]!=word[idx])
            return false;
        char temp=board[cr][cc];
        board[cr][cc]='-1';
        
        bool up=helper(board,cr-1,cc,r,c,word,idx+1);
        bool right=helper(board,cr,cc+1,r,c,word,idx+1);
        bool down=helper(board,cr+1,cc,r,c,word,idx+1);
        bool left=helper(board,cr,cc-1,r,c,word,idx+1);
        
        board[cr][cc]=temp;
        
        return (up || right || down || left);
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(helper(board,i,j,r,c,word,0))
                        return true;
                }
            }
        }
       return false;
    }
};