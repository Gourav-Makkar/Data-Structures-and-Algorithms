class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int>s;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            s.clear();
            for(int j=0;j<n;j++)
            {
                if(s.find(matrix[i][j])!=s.end())
                    return false;
                s.insert(matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            s.clear();
            for(int j=0;j<n;j++)
            {
                if(s.find(matrix[j][i])!=s.end())
                    return false;
                s.insert(matrix[j][i]);
            }
        }
        return true;
    }
};