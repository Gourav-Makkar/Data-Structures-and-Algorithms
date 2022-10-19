typedef long long int ll;
class Solution {
public:
    
    bool check(ll mx,vector<int>nums)
    {
        vector<ll>arr(nums.begin(),nums.end());
        for(int i=0;i<arr.size()-1;i++)
        {
           if(arr[i]>mx)
               return false;
            arr[i+1]-=(mx-arr[i]);
        }
        if(arr[arr.size()-1]<=mx)
            return true;
        else
            return false;
        
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int st=INT_MAX;
        int en=INT_MIN;
        int n=nums.size();
        int ans;
        for(int i=0;i<n;i++)
        {
            st=min(st,nums[i]);
            en=max(en,nums[i]);
        }
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
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