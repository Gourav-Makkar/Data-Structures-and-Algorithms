class Solution {
public:
    
    void helper(int open,int close,string curr,vector<string>&ans)
    {
        if(open==0 && close==0)
        {
            ans.push_back(curr);
            return;
        }
        if(open!=0)
        {
            curr.push_back('(');
            helper(open-1,close,curr,ans);
            curr.pop_back();
        }
        if(close>open)
        {
            curr.push_back(')');
            helper(open,close-1,curr,ans);
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        vector<string>ans;
        
        helper(open,close,"",ans);
        return ans;
    }
};