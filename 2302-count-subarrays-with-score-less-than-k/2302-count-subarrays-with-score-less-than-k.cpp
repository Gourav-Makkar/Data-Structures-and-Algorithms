class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n=nums.size();
        long long i=0,j=0;
        long long ans=0;
        long long cs=0;
        
        while(j<n)
        {
            cs+=nums[j];
            
//             if(cs*(j-i+1)<k)
//             {
//                 ans+=j-i+1;
//             }
//             else
//             {
                while(cs*(j-i+1)>=k)
                {
                    cs=cs-nums[i];
                    i++;
                }
                ans+=j-i+1;
            
            j++;
        }
        return ans;
    }
};