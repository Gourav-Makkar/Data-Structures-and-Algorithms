class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int rem=0;
        
        vector<int>temp=intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<temp[1])
            {
                rem++;
                temp[1]=min(temp[1],intervals[i][1]);
            }
            else
                temp=intervals[i];
        }
        return rem;
    }
};