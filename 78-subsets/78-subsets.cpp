class Solution {
public:
    void helper(vector<int>ip,vector<int>op,vector<vector<int>>&ans,int curr)
    {
        if(curr>=ip.size())
        {
            ans.push_back(op);
            return;
        }
        vector<int>op1=op,op2=op;
        op2.push_back(ip[curr]);
        
        helper(ip,op1,ans,curr+1);
        helper(ip,op2,ans,curr+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        helper(nums,op,ans,0);
        
        return ans;
    }
};