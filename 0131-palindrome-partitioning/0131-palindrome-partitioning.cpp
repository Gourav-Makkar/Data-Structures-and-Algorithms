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
        int n=s.size();
        if(n==0)
        {
           ans.push_back(temp);
           return;
        }
        
        for(int i=0;i<n;i++)
        {
            string curr=s.substr(0,i+1);
            string rem=s.substr(i+1,n-i+1);
            
            if(isPalindrome(curr))
            {
                temp.push_back(curr);
                helper(rem,temp,ans);
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