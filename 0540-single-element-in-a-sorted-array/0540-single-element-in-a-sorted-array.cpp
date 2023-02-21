class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        int st=0,en=n-1;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            if(mid==0 && nums[mid]!=nums[mid+1])
                return nums[mid];
            
            if(mid==n-1 && nums[mid]!=nums[mid-1])
                return nums[mid];
            
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
              return nums[mid];
            
            if(nums[mid]==nums[mid-1])
            {
                if(mid%2==0)
                    en=mid-1;
                else
                    st=mid+1;
            }
            if(nums[mid]==nums[mid+1])
            {
                if(mid%2==0)
                    st=mid+1;
                else
                    en=mid-1;
            }
        }
        return -1;
    }
};