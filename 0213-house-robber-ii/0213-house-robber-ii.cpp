class Solution {
public:
    
    int helper(vector<int>&nums)
    {
        int prev2=0,prev=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            int take=nums[i];
            if(i-2>=0)
                take+=prev2;
            int notTake=0+prev;
            
            prev2=prev;
            prev=max(take,notTake);
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)
            return nums[0];
        
        vector<int>temp1,temp2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        
        int ans1=helper(temp1);
        int ans2=helper(temp2);
        
        return max(ans1,ans2);
    }
};