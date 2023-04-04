class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefmx(n),sufmn(n);
        
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
            prefmx[i]=mx;
        }
        
        int mn=INT_MAX;
        
        for(int i=n-1;i>=0;i--)
        {
            sufmn[i]=mn;
            mn=min(mn,nums[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(prefmx[i]<=sufmn[i])
                return i+1;
        }
        return n;
    }
};