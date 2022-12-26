class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n);
        
        int mx=height[0];
        lmax[0]=mx;
        
        for(int i=1;i<n;i++)
        {
            mx=max(mx,height[i]);
            lmax[i]=mx;
        }
        
        vector<int>rmax(n);
        mx=height[n-1];
        rmax[n-1]=mx;
        
        for(int i=n-2;i>=0;i--)
        {
            mx=max(mx,height[i]);
            rmax[i]=mx;
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(lmax[i],rmax[i]) - height[i];
        }
        
        return ans;
    }
};