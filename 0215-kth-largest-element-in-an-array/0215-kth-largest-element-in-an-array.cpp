class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i=0,n=nums.size();
        
        while(i<n)
        {
            pq.push(nums[i]);
            
            if(pq.size()>k)
                pq.pop();
            i++;
        }
        return pq.top();
    }
};