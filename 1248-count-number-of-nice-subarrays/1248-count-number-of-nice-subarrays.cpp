class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        list<int>l;
        int i=0,j=0;
        int ans=0,ct=0;
        
        while(j<n)
        {
            if(nums[j]%2!=0)
            {
                l.push_back(j);
                ct++;
            }
            
            while(ct>k)
            {
                if(nums[i]%2!=0)
                {
                    l.pop_front();
                    ct--;
                }
                i++;
            }
            
            if(ct==k)
            {
                int idx=l.front();
                ans+=idx-i+1;
            }
           j++; 
        }
        return ans;
    }
};