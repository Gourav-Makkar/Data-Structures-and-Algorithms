class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        int target=sum-x;
        int ans=INT_MIN;
        if(target<0)
            return -1;
        int i=0,j=0;
        int cs=0;
        while(j<n)
        {
            cs+=nums[j];
            while(cs>target)
            {
                cs-=nums[i];
                i++;
            }
            if(cs==target)
                ans=max(ans,j-i+1);
            j++;
        }
        if(ans==INT_MIN)
            return -1;
        return n-ans;
    }
};