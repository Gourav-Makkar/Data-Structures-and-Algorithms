class Solution {
public:
    
    void helper(int idx,string &s,int prev,string curr,vector<string>&ans,unordered_set<string>&st)
    {
        int n=s.size();
        if(idx==n)
        {
            if(prev==n)
            {
                curr.pop_back();
                ans.push_back(curr);
            } 
            return;
        }
        
        string temp=s.substr(prev,idx-prev+1);
        if(st.find(temp)!=st.end())
          helper(idx+1,s,idx+1,curr+temp+" ",ans,st);
        
        helper(idx+1,s,prev,curr,ans,st);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<string>ans;
        unordered_set<string>st;
        
        for(auto it:wordDict)
            st.insert(it);
        
        helper(0,s,0,"",ans,st);
        
        return ans;
    }
};