class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n+1,0);
        for(int i=0;i<n;i++)
        {
            temp[nums[i]]++;
        }
        vector<int>ans;
        for(int i=1;i<n+1;i++)
        {
            if(temp[i]>1)
            {
                ans.push_back(i);
                break;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            if(temp[i]==0)
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};