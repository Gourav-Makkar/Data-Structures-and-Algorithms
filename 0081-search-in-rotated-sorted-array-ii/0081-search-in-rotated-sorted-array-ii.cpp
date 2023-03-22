class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n=nums.size();
       int st=0,en=n-1;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]==nums[st] && nums[mid]==nums[en])
            {
                st++;
                en--;
            }
            else if(nums[mid]<=nums[en])
            {
                if(nums[mid]<target && nums[en]>=target)
                    st=mid+1;
                else
                    en=mid-1;
            }
            else
            {
                if(target>=nums[st] && target<nums[mid])
                    en=mid-1;
                else
                    st=mid+1;
            }
        }
        return false;
    }
};