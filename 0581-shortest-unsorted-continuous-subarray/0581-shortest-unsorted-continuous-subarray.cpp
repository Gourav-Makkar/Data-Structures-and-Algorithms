class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return 0;
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int i=0,j=n-1;
        
        while(i<j)
        {
            if(nums[i]==temp[i])
                i++;
            if(nums[j]==temp[j])
                j--;
            if(i==j)
                return 0;
            else if(nums[i]!=temp[i] && nums[j]!=temp[j])
                break;
        }
        return j-i+1;
    }
};