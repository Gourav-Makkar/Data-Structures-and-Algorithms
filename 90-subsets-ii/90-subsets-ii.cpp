class Solution {
public:
    
    void helper(vector<int>ip,vector<int>op,int idx,vector<vector<int>>&ans)
    {
        ans.push_back(op);
        if(idx>=ip.size())
            return;
        for(int i=idx;i<ip.size();i++)
        {
            if(i>idx && ip[i]==ip[i-1])
                continue;
            op.push_back(ip[i]);
            helper(ip,op,i+1,ans);
            op.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>op;
        helper(nums,op,0,ans);
        
        return ans;
    }
};