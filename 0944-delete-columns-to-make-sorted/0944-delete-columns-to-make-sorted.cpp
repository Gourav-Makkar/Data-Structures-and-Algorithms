class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r=strs.size();
        int c=strs[0].size();
        int ans=0;
        
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r-1;j++)
            {
                if(strs[j][i]>strs[j+1][i])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};