class Solution {
public:
    
    bool helper(vector<vector<char>>& board,int cr,int cc, string word,string curr,int idx)
    {
        if(curr==word)
            return true;
        if(cr<0 || cr==board.size() || cc<0 || cc==board[0].size() || board[cr][cc]=='-1' || board[cr][cc]!=word[idx])
            return false;
        
        char temp=board[cr][cc];
        
        curr.push_back(board[cr][cc]);
        board[cr][cc]='-1';
        
        bool up=helper(board,cr-1,cc,word,curr,idx+1);
        
        bool right=helper(board,cr,cc+1,word,curr,idx+1);
        
        bool down=helper(board,cr+1,cc,word,curr,idx+1);
        
        bool left=helper(board,cr,cc-1,word,curr,idx+1);
        
        curr.pop_back(); 
        board[cr][cc]=temp;
        
        return(
        up || right || down || left);
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                string curr="";
                if(board[i][j]==word[0])
                {
                    if(helper(board,i,j,word,curr,0))
                        return true;
                }
            }
        }
        return false;
        
        
    }
};