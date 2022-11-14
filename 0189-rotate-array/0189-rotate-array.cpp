class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0 || n==1 || k==n)
            return;
        if(k>n)
            k=k%n;
        
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        
        reverse(nums.begin(),nums.end());
    }
};