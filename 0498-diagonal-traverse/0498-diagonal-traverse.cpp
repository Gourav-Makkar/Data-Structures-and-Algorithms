class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        
        vector<int>ans;
        
        int curr=0;
        bool flag=false;
        
        while(curr<=(r-1+c-1))
        {
            if(flag)
            {
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        if(i+j==curr)
                           ans.push_back(mat[i][j]); 
                    }
                }
            }
            else
            {
                for(int i=r-1;i>=0;i--)
                {
                    for(int j=0;j<c;j++)
                    {
                        if(i+j==curr)
                          ans.push_back(mat[i][j]);      
                    }
                }
            }
            curr++;
            flag=!flag;
        }
        
        return ans;
    }
};