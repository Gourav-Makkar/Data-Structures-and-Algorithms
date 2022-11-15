class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ps(n);
        ps[0]=1;
        for(int i=1;i<n;i++)
            ps[i]=nums[i-1]*ps[i-1];
        vector<int>ss(n);
        ss[n-1]=1;
        for(int i=n-2;i>=0;i--)
            ss[i]=nums[i+1]*ss[i+1];
        
        vector<int>ans(n);
        for(int i=0;i<n;i++)
            ans[i]=ps[i]*ss[i];
        return ans;
    }
};