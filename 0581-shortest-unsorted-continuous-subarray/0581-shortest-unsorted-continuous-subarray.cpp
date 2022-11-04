class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return 0;
        stack<int>mx;
        stack<int>mn;
        
        for(int i=0;i<n;i++)
        {
            if(mx.empty() || nums[i]>=mx.top())
                mx.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(mn.empty() ||nums[i]<=mn.top())
                mn.push(nums[i]);
        }
        
        int i=0,j=n-1;
        
        while(i<=j)
        {
            if(i==j)
                return 0;
            
            if(nums[i]!=mn.top() && nums[j]!=mx.top())
                break;
            if(nums[i]==mn.top())
            {
                i++;
                mn.pop();
            }
            if(nums[j]==mx.top())
            {
                j--;
                mx.pop();
            } 
        }
        
        return j-i+1;
    }
};