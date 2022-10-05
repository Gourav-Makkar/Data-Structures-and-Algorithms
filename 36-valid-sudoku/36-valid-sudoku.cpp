class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>>rows(9),columns(9),boxes(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                int n=board[i][j]-'0';
                int bidx=i/3 * 3 + j/3;
                if(rows[i].count(n))
                    return false;
                if(columns[j].count(n))
                    return false;
                if(boxes[bidx].count(n))
                    return false;
                
                rows[i].insert(n);
                columns[j].insert(n);
                boxes[bidx].insert(n);
            }
        }
        return true;
    }
};