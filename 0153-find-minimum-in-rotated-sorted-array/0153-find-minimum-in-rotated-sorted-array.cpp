class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0,en=n-1;
        int ans=INT_MAX;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(nums[mid]<=nums[en])
            {
                en=mid-1;
                ans=min(ans,nums[mid]);
            }
            else
                st=mid+1;
        }
        return ans;
    }
};