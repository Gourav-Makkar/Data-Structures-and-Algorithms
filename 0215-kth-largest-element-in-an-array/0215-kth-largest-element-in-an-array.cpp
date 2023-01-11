class Solution {
public:
    
    
    int check(vector<int>&nums,int mid)
    {
        int ct=0;
        for(auto it:nums)
        {
            if(it>=mid)
                ct++;
        }
        return ct;
    }
    
    bool find(vector<int>&nums,int mid)
    {
        for(auto it:nums)
        {
            if(it==mid)
                return true;
        }
        return false;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int st=INT_MAX,en=INT_MIN;
        
        for(auto it:nums)
        {
            st=min(st,it);
            en=max(en,it);
        }
        
        int ans=-1;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
        
            if(check(nums,mid)>=k )
            {
               if(find(nums,mid))
                  ans=mid;
               st=mid+1;
            }
            else
                en=mid-1;
        }
        return ans;
    }
};