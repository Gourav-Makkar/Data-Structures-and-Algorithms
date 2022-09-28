class Solution {
public:
    
    void helper(vector<int>ip,vector<int>op,vector<vector<int>>&ans)
    {
        if(ip.size()==0)
        {
            ans.push_back(op);
            return;
        }
        for(int i=0;i<ip.size();i++)
        {
            vector<int>ip1=ip;
            op.push_back(ip[i]);
            ip1.erase(ip1.begin()+i);
            helper(ip1,op,ans);
            op.pop_back();
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        helper(nums,op,ans);
        
        return ans;
    }
};