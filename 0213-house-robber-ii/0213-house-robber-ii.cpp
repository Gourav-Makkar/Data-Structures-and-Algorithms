class Solution {
public:
    
    int helper(vector<int>arr)
    {
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<arr.size();i++)
        {
            int pick=arr[i];
            if(i-2>=0)
                pick+=prev2;
            int nonPick=0+prev;
            
            int curr=max(pick,nonPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        if(nums.size()==1)
            return nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums.size()-1)
                temp1.push_back(nums[i]);
            if(i!=0)
                temp2.push_back(nums[i]);
                
        }
        int ans1=helper(temp1);
        int ans2=helper(temp2);
        
        return max(ans1,ans2);
    }
};