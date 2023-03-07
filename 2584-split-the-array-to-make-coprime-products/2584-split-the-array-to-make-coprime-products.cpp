class Solution {
public:
    
    void findPrimeFact(int n,vector<int>&f)
    {
         int t=n;
         for(int i=2;i<=sqrt(t);i++)
         {
            if(n%i==0)
            {
             f.push_back(i);
             while(n%i==0)
                 n=n/i;
            }
         }
        if (n>1)
            f.push_back(n);
    }
    
    int findValidSplit(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m,curr;
        
        if(n==1)
            return -1;
        
        for(auto it:nums)
        {
            vector<int>f;
            findPrimeFact(it,f);
            for(auto it1:f)
                m[it1]++;
        }
        int common=0;
        for(int i=0;i<n;i++)
        {
            vector<int>f;
            findPrimeFact(nums[i],f);
            for(auto it:f)
                common += (curr[it]++ == 0) - (curr[it] == m[it]);
            
            if(common==0 && i!=n-1)
                return i;
        }
        return -1;
    }
};