class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        
        int lmax=INT_MIN,rmax=INT_MIN;
        long long ans=0;
        
        while(l<=r)
        {
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            
            if(height[l]<=height[r])
            {   
                ans+=min(lmax,rmax)-height[l];
                l++;
            }
            else
            {
                ans+=min(lmax,rmax)-height[r];
                r--;
            }
        }
        return ans;
    }
};