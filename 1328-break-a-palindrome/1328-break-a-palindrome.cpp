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
        for(int i=0;i<n/2;i++)
        {
            if(palindrome[i]!='a')
            {
               palindrome[i]='a';
               return palindrome;
            }
        }
        palindrome[n-1]=palindrome[n-1]+1;
        return palindrome;
    }
};