class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int p=1;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                p=p*nums[i];
            else
                ct++;
        }
        if(ct==n)
            p=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0 && ct==0)
                ans.push_back(p/nums[i]);
            else if(nums[i]!=0 && ct>0)
                ans.push_back(0);
            else if(nums[i]==0 && ct>1)
            {
                ans.push_back(0);
            }
            else if(nums[i]==0 && ct==1)
                ans.push_back(p);
        }
        return ans;
    }
};