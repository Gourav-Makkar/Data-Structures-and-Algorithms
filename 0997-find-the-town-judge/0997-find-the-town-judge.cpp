class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>tr(n+1,0),vis(n+1,0);
        for(auto it:trust)
        {
            tr[it[1]]++;
            vis[it[0]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0 && tr[i]==n-1)
                return i;
        }
        return -1;
    }
};