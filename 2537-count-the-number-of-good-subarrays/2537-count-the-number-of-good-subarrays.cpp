class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        long long n=nums.size();
        
        int i=0,j=0;
        long long ans=0,ct=0;
        while(j<n)
        {
            if(m[nums[j]]>=1)
                ct+=m[nums[j]];
            m[nums[j]]++;
            
            while(ct>=k)
            {
                if(m[nums[i]]>=2)
                   ct-=(m[nums[i]]-1);
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            
            if(ct<k)
                ans+=(j-i+1);
            j++;
        }
        return n*(n+1)/2 - ans;
    }
};