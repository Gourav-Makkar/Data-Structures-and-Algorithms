class Solution {
public:
    
    int helper(int idx,vector<int>&nums,int k,unordered_map<int,int>&m)
    {
        int n=nums.size();
        
        if(idx==n)
           return 1;
        
        int nottake=helper(idx+1,nums,k,m);
        
        int take=0;
        if(m.size()==0 || (m.size()!=0 && m[nums[idx]+k]==0 && m[nums[idx]-k]==0))
        {
            m[nums[idx]]++;
            take=helper(idx+1,nums,k,m);
            m[nums[idx]]--;
        }
        
        return take+nottake;
        
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        
        return helper(0,nums,k,m)-1;
    }
};