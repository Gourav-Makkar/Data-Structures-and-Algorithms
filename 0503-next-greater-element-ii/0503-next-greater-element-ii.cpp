class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       stack<int>st;
       int n=nums.size();
       vector<int>ans(n);
        
        
       st.push(nums[(2*n-1)%n]);
       ans[(2*n-1)%n]=-1;
       
       for(int i=2*n-2;i>=0;i--)
       {
           while(!st.empty() && nums[i%n]>=st.top())
               st.pop();
           int ele=(st.empty())?-1:st.top();
           ans[i%n]=ele;
           st.push(nums[i%n]);
       }
       return ans;
    }
};