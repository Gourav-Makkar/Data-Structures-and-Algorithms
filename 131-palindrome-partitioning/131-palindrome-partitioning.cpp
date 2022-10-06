class Solution {
public:
    
    bool isPalindrome(string s)
    {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void helper(string s,vector<string>curr,vector<vector<string>>&ans,int n)
    {
        if(s.length()==0)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            string s1=s.substr(0,i+1);
            string s2=s.substr(i+1,s.length()-i+1);
            
            if(isPalindrome(s1))
            {
                curr.push_back(s1);
                helper(s2,curr,ans,n);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        helper(s,temp,ans,s.length());
        
        return ans;
    }
};