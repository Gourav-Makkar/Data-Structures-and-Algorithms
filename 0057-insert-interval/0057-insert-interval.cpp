class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0],newInterval[1]});
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>ans;
        int st=intervals[0][0],en=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
           if(intervals[i][0]<=en)
           {
               en=max(en,intervals[i][1]);
           }
           else
           {
              ans.push_back({st,en});
              st=intervals[i][0];
              en=intervals[i][1];
           }
        }
        
        ans.push_back({st,en});
        return ans;
    }
};