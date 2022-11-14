class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        long long int op=0;
        sort(nums.begin(),nums.end());
        
        int i=0,j=1;
        
        long long int curr=1;
        long long int ans=1;
        while(j<n)
        {
            op+=curr*(nums[j]-nums[j-1]);
            curr++;
            if(op<=k)
            {
                ans=max(ans,curr);
            }
            else if(op>k)
            {
               while(op>k)
               {
                    op-=nums[j]-nums[i];
                    curr--;
                    i++;
               }    
            }
            j++;
        }
        return int(ans);
    }
};