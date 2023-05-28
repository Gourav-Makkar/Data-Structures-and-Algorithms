class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        
        int cs=intervals[0][0],ce=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
            int ns=intervals[i][0],ne=intervals[i][1];
            if(ce<ns)
            {
                ans.push_back({cs,ce});
                cs=ns;
                ce=ne;
            }
            else
            {
                cs=min(cs,ns);
                ce=max(ce,ne);
            }
        }
        ans.push_back({cs,ce});
        return ans;
    }
};