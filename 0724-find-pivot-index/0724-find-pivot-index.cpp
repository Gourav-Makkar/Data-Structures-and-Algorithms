class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        int curr=0;
        for(int i=0;i<n;i++)
        {
            sum-=nums[i];
            
            if(sum==curr)
                return i;
            
            curr+=nums[i];
        }
        return -1;
    }
};