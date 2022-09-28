class Solution {
public:
    
    void helper(vector<int>ip,int idx,vector<vector<int>>&ans)
    {
       if(idx==ip.size())
       {
           ans.push_back(ip);
           return;
       }
       
        for(int i=idx;i<ip.size();i++)
        {
            swap(ip[idx],ip[i]);
            helper(ip,idx+1,ans);
            swap(ip[idx],ip[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(nums,0,ans);
        
        return ans;
    }
};