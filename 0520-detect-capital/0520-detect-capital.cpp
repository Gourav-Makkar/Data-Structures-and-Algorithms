class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        
        if(word[0]<97)
        {
            if(word[1]<97)
            {
                for(int i=2;i<n;i++)
                {
                    if(word[i]>=97)
                        return false;
                }
            }
            else
            {
                for(int i=2;i<n;i++)
                {
                    if(word[i]<97)
                        return false;
                }
            }
        }
        else
        {
            for(int i=1;i<n;i++)
            {
                if(word[i]<97)
                    return false;
            }
        }
        
        return true;
    }
};