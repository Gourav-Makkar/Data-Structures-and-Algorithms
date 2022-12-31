class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        
        vector<int>ans;
        
        int ct=r*c;
        int curr=0;
        bool flag=false;
        
        while(ct!=0)
        {
            if(flag)
            {
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        if(i+j==curr)
                        {
                            ans.push_back(mat[i][j]);
                            ct--;
                        }
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
                        {
                            ans.push_back(mat[i][j]);
                            ct--;
                        }
                    }
                }
            }
            
            curr++;
            flag=!flag;
        }
        
        return ans;
    }
};