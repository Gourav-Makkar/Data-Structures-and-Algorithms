class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>p;
        
        for(int i=0;i<n;i++)
        {
            p.push(nums[i]);
            if(p.size()>k)
                p.pop();
        }
        return p.top();
    }
};