class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int pe=points[0][1];
        
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>pe)
            {
                ans++;
                pe=points[i][1];
            }
            
            pe=min(points[i][1],pe);   
        }
        return ans;
    }
};