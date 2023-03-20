class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        bool found=false;
        unordered_map<int,int>m;
        m[0]=1;
        int n=nums.size(),i=0,cs=0,ans=0;
        
        while(i<n)
        {
            if(nums[i]<k)
                cs--;
            
            else if(nums[i]>k)
                cs++;
            
            else
                found=true;
            
            if(found)
                ans+= m[cs] + m[cs-1];
            else
                m[cs]++;
            i++;
        }
        return ans;
    }
};