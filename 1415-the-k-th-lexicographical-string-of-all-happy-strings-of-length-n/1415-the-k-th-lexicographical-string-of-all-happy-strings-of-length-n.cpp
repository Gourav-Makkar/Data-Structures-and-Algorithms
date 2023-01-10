class Solution {
public:
    
    void helper(int n,string curr,vector<string>&ans)
    {
        int s=curr.size();
        if(s>n)
            return;
        if(s==n)
        {
            ans.push_back(curr);
            return;
        }
        
        if(s==0)
        {
            curr+='a';
            helper(n,curr,ans);
            curr.pop_back();
            
            curr+='b';
            helper(n,curr,ans);
            curr.pop_back();
            
            curr+='c';
            helper(n,curr,ans);
            curr.pop_back();
        }
        else
        {
            if(curr[s-1]!='a')
            {
               curr+='a';
               helper(n,curr,ans);
               curr.pop_back();
            }
            
            if(curr[s-1]!='b')
            {
            curr+='b';
            helper(n,curr,ans);
            curr.pop_back();
            }
            
            if(curr[s-1]!='c')
            {
            curr+='c';
            helper(n,curr,ans);
            curr.pop_back();
            }
        }
        
    }
    
    string getHappyString(int n, int k) {
        vector<string>ans;
        
        helper(n,"",ans);
        sort(ans.begin(),ans.end());
        if(ans.size()<k)
            return "";
        return ans[k-1];
    }
};