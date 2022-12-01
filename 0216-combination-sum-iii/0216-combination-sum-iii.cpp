class Solution {
public:
    
    void helper(int idx,int sum,int n,vector<int>curr,vector<vector<int>>&ans,int from)
    {
        if(sum==0 && idx==n)
        {
            ans.push_back(curr);
            return;
        }
        if(idx==n)
            return;
        for(int i=from;i<=9;i++)
        {
            if(i<=sum)
            {
                curr.push_back(i);
                helper(idx+1,sum-i,n,curr,ans,i+1);
                curr.pop_back();
            }
            else
                break;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        
        int from=1;
        helper(0,n,k,curr,ans,from);
        return ans;
    }
};