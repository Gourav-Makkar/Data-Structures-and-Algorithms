class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int column=mat[0].size();
        
        vector<vector<int>>ans;
        vector<int>temp;
         if(r*c>row*column ||r*c<row*column)
             return mat;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                temp.push_back(mat[i][j]);
            }
        }
        int ct=0;
        for(int i=0;i<r && ct<temp.size();i++)
        {
            vector<int>v;
            for(int j=0;j<c;j++)
            {
                v.push_back(temp[ct]);
                ct++;
            }
            ans.push_back(v);
        }
        return ans;
    }
};