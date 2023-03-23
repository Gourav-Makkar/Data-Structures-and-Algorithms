class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int st=0,en=n-1;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            if((mid==st || nums[mid]>nums[mid-1]) && (mid==en || nums[mid]>nums[mid+1]))
                return mid;
            else if(nums[mid]<nums[mid+1])
                st=mid+1;
            else if(nums[mid]<nums[mid-1])
                en=mid-1;
        }
        return -1;
    }
};