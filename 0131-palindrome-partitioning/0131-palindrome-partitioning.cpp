class Solution {
public:
    
    bool isPalindrome(string s)
    {
        int n=s.size();
        int i=0,j=n-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void helper(string s,vector<string>&temp,vector<vector<string>>&ans)
    {
        if(s.size()==0)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<s.size();i++)
        {
            string s1=s.substr(0,i+1);
            string s2=s.substr(i+1,s.size());
            
            if(isPalindrome(s1))
            {
                temp.push_back(s1);
                helper(s2,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        
        helper(s,temp,ans);
        return ans;
    }
};