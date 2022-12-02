class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int i=0,j=0;
        
        int n=nums.size();
        int cs=0;
        
        while(j<n)
        {
            cs+=nums[j];
            while(cs>=target)
            {
                if(cs>=target)
                  ans=min(ans,j-i+1);
                cs-=nums[i];
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};