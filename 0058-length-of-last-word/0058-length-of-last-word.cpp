class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans;
        string word="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(word.size()!=0)
                    ans=word.size();
                word="";
            }
            else
              word+=s[i];
        }
        if(word.size()!=0)
          return word.size();
        return ans;
    }
};