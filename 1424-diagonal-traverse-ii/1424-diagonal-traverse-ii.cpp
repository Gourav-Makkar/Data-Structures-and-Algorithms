class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        map<int,vector<int>>m;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[i+j].push_back(nums[i][j]);
            }
        }
        
        for(auto it:m)
        {
            vector<int>temp=it.second;
            for(auto v:temp)
                ans.push_back(v);
        }
        return ans;
    }
};