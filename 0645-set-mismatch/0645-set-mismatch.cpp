class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int mis=1,rep=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
                rep=abs(nums[i]);
            else
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                mis=i+1;
        }
        vector<int>ans;
        ans.push_back(rep);
        ans.push_back(mis);
        
        return ans;
    }
};