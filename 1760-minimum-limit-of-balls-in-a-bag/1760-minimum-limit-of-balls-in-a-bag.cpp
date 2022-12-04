class Solution {
public:
    
    bool check(int mx,vector<int>nums,int op)
    {
        int ct=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>mx)
            {
                if(nums[i]%mx==0)
                    ct+=nums[i]/mx -1;
                else
                    ct+=nums[i]/mx;
            }
        }
        return (ct<=op);
    }
    
    int minimumSize(vector<int>& nums, int op) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int st=1,en=nums[n-1];
        
        int ans;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            if(check(mid,nums,op))
            {
                ans=mid;
                en=mid-1;
            }
            else
                st=mid+1;
        }
        return ans;
    }
};