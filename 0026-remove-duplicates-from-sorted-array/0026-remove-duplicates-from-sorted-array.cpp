class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[k-1])
            {
                swap(nums[i],nums[k]);
                k++;
            }
        }
        return k;
    }
};