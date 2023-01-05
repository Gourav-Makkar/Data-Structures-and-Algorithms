class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int prev=0,pe=points[0][1];
        
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>pe)
            {
                ans++;
                prev=i;
                pe=points[i][1];
            }
            else
            {
                 if(points[i][1]<points[prev][1])
                 {
                     prev=i;
                 }
                 pe=min(points[i][1],points[prev][1]);
            }
            
        }
        return ans;
    }
};