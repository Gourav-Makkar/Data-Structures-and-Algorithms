class Solution {
public:
    int rob(vector<int>& nums) {
        // Your code here
        // int n=nums.size();
        // vector<int>dp(n,-1);
        // dp[0]=nums[0];
        
        // for(int i=1;i<n;i++)
        // {
        //     int pick=nums[i];
        //     if(i-2>=0)
        //       pick+=dp[i-2];
        //     int nonPick=0+dp[i-1];
            
        //     dp[i]=max(pick,nonPick);
        // }
        // return dp[n-1];
        
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i-2>=0)
              pick+=prev2;
            int nonPick=0+prev;
            
            int curr=max(pick,nonPick);
            prev2=prev;
            prev=curr;
            
        }
        return prev;
    }
};