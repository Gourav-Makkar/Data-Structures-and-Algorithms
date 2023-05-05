class Solution {
public:
    
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        int n=s.size(),i=0,j=0,ct=0,ans=0;
        
        while(j<n)
        {
            if(isVowel(s[j]))
                ct++;
            
            if(j-i+1==k)
            {
                ans=max(ans,ct);
                if(isVowel(s[i]))
                    ct--;
                i++;
            }
            j++;
        }
        return ans;
    }
};