class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int ans;
        int closest=INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                int cs=nums[i]+nums[l]+nums[r];
                
                if(abs(target-cs)<=closest)
                {
                    ans=cs;
                    closest=abs(target-cs);
                }
                if(cs==target)
                    {
                        return cs;
                    }
                    else if(cs<target)
                        l++;
                    else
                        r--;
            }
        }
        return ans;
    }
};