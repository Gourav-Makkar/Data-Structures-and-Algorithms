class Solution {
public:
    
    int first(vector<int>&nums)
    {
        int st=0,en=nums.size()-1;
        int ans;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(nums[mid]<=0)
            {
                st=mid+1;
            }
            else
            {
                ans=mid;
                en=mid-1;
            }
        }
        return nums.size()-ans;
    }
    int last(vector<int>&nums)
    {
        int st=0,en=nums.size()-1;
        int ans=-1;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(nums[mid]<0)
            {
                ans=mid;
                st=mid+1;
            }
            else
            {
                en=mid-1;
            }
        }
        return ans-0+1;
    }
    
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        
        int f=first(nums);
        int l=last(nums);
        
        return max(f,l);
        
    }
};