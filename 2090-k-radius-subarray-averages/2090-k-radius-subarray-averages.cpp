class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n);
        
        if(k==0)
            return nums;
        if(n==1 || k>n)
        {
            vector<int>res(n,-1);
            return res;
        }
        
        long long ls=0;
        for(int i=0;i<k;i++)
        {
            ls+=nums[i];
            ans[i]=-1;
        }
        
        long long rs=0;
        for(int i=k;i<=k+k && i<n;i++)
        {
            rs+=nums[i];
        }
        
        for(int i=k;i<n-k;i++)
        {
           int s=2*k+1;
           int val=(ls+rs)/s;
           ans[i]=val;
           if(i==n-k-1)
               break;
           ls-=nums[i-k];
           rs+=nums[i+k+1];
        }
        
        for(int i=n-k;i<n;i++)
            ans[i]=-1;
        
        return ans;
    }
};