class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>nextGr(n);
        
        st.push(2*n-1);
        nextGr[(2*n-1)%n]=-1;
        
        for(int i=2*n-2;i>=0;i--)
        {
            while(!st.empty() && nums[i%n]>=nums[st.top()%n])
                st.pop();
            int idx=(st.empty())?-1:st.top();
            if(idx==-1)
                nextGr[i%n]=-1;
            else
                nextGr[i%n]=nums[idx%n];
            st.push(i);
        }
        return nextGr;
    }
};