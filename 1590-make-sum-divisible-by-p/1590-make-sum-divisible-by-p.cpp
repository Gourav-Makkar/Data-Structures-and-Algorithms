class Solution {
public:
    
    int findMinSubarray(vector<int>&nums,int rem,int p){
        long long cs=0;
        int n=nums.size();
        int j=0;
        int ans=INT_MAX;
        unordered_map<int,int>m;
        m[0]=-1;
        while(j<n)
        {
            cs=(cs+nums[j])%p;
            int t=(cs-rem+p)%p;
             
            if(m.find(t)!=m.end())
                ans=min(ans,j-m[t]);
            m[cs]=j;
            j++;
        }
        return ans;
    }
    
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(auto x:nums)
            sum+=x;
        
        if(sum%p==0)
            return 0;
        int rem=sum%p;
       
        int ans=findMinSubarray(nums,rem,p);
        if(ans==INT_MAX || ans==nums.size())
            return -1;
        return ans;
    }
};