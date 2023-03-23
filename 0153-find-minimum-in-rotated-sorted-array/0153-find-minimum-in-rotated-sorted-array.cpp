class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        
        int st=0,en=n-1,ans=INT_MAX;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
             ans=min(ans,nums[mid]);
            
            if(nums[mid]>nums[en])
            {
                st=mid+1;
            }
            else
                en=mid-1;
        }
        return ans;
    }
};