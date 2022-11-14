class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            int idx=i+1;
            int ele=-1;
            while(idx%n!=i)
            {
                if(nums[idx%n]>nums[i])
                {
                    ele=nums[idx%n];
                    break;
                }
                idx++;
            }
            ans.push_back(ele);
        }
        return ans;
    }
};