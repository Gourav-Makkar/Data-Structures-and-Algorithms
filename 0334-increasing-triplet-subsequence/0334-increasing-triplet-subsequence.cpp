class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>rightMx(n);
        rightMx[n-1]=INT_MIN;
        int mx=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            rightMx[i]=mx;
            mx=max(mx,nums[i]);
        }
        
        int mn=nums[0];
        for(int i=1;i<n-1;i++)
        {
            if(mn<nums[i] && nums[i]<rightMx[i])
                return true;
            mn=min(mn,nums[i]);
        }
        return false;
    }
};