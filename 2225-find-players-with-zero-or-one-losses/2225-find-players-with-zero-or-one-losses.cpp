class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>m;
        vector<vector<int>>ans;
        for(int i=0;i<matches.size();i++)
        {
            int l=matches[i][1];
            m[l]++;
        }
        set<int>win,los;
        for(int i=0;i<matches.size();i++)
        {
            int w=matches[i][0];
            int l=matches[i][1];
            
            if(m[w]==0)
                win.insert(w);
            if(m[l]==1)
                los.insert(l);
        }
        
        vector<int>w(win.begin(),win.end());
        ans.push_back(w);
        vector<int>l(los.begin(),los.end());
        ans.push_back(l);
        
        return ans;
        
    }
};