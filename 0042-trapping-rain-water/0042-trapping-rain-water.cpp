class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n),rmax(n);
        lmax[0]=height[0];
        int mx=height[0];
        
        for(int i=1;i<n;i++)
        {
            mx=max(mx,height[i]);
            lmax[i]=mx;
        }
        
        rmax[n-1]=height[n-1];
        mx=height[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            mx=max(mx,height[i]);
            rmax[i]=mx;
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans+=(min(rmax[i],lmax[i])-height[i]);
        }
        return ans;
    }
};