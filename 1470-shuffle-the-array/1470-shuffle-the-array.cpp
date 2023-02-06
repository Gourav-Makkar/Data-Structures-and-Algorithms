class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        int i=0;
        int j=0;
        while(i<2*n)
        {
            ans[i]=nums[j];
            ans[i+1]=nums[n+j];
            j++;
            i+=2;
        }
        return ans;
    }
};