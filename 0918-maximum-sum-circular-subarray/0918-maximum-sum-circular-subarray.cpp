class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans1=INT_MIN,cs=0,sum=0;
        
        for(int i=0;i<n;i++)
        {
           if(cs+nums[i]>nums[i])
               cs+=nums[i];
            else
               cs=nums[i];
            ans1=max(ans1,cs);
        }
        
        if(ans1<0)
            return ans1;
        
        int ans2=INT_MIN;
        cs=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            if(cs+nums[i]>nums[i])
              cs+=nums[i];
            else
                cs=nums[i];
            ans2=max(ans2,cs);
        }
        int temp=sum- (-(ans2));
        
        return max(temp,ans1);
    }
};