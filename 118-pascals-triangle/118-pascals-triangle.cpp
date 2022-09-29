class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++)
        {
            vector<int>v;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    v.push_back(1);
                else
                {
                    v.push_back(ans[i-1][j]+ans[i-1][j-1]);
                }
            }
            ans[i]=v;
        }
        return ans;
        
    }
};