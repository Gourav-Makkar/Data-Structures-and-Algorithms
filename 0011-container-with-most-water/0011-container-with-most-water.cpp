class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        
        int l=0,r=n-1,ans=0;
        
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                ans=max(ans,(r-l)*height[l]);
                l++;
            }
            else
            {
                ans=max(ans,(r-l)*height[r]);
                r--;
            }
        }
        return ans;
    }
};