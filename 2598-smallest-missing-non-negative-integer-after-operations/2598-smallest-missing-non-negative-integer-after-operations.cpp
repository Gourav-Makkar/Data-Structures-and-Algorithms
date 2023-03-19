class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                int val=abs(nums[i]);
                int rem=val%value;
                if(rem==0)
                   nums[i]=0;
                else
                    nums[i]=value-rem;
            }
            else
                nums[i]=nums[i]%value;
        }
        
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                int ct=m[nums[i]];
                int temp=value*ct+nums[i];
                m[nums[i]]++;
                nums[i]=temp;
            }
        }
        int ans=0;
        unordered_set<int>s;
        for(auto it:nums)
            s.insert(it);
        
        while(true)
        {
            if(s.find(ans)!=s.end())
                ans++;
            else
                break;
        }
         return ans;   
        
    }
};