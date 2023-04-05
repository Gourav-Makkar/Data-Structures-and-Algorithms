class Solution {
public:
    
    bool check(long long mid,vector<int>temp)
    {
        vector<long long>nums;
        for(auto it:temp)
            nums.push_back(it);
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<mid)
            {
                long long ct=mid-nums[i-1];
                nums[i-1]+=ct;
                nums[i]-=ct;
            }
            else if(nums[i-1]>mid)
                return false;
        }
        return nums[nums.size()-1]<=mid;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int st=0,en=INT_MIN,ans;
        
        for(auto it:nums)
            en=max(it,en);
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            // cout<<st<<" "<<en<<endl;
            
            if(check(mid,nums))
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