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
    
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(palindrome.length()==1)
            return "";
        for(int i=0;i<n;i++)
        {
            if(palindrome[i]!='a')
            {
                string s=palindrome;
                s[i]='a';
                if(!isPalindrome(s))
                {
                    palindrome[i]='a';
                    break;
                }
            }
            if(i==n-1)
            {
                palindrome[i]=palindrome[i]+1;
            }
        }
        return palindrome;
    }
};