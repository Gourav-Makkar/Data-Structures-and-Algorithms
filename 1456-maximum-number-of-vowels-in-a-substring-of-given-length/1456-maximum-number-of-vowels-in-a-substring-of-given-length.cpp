class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int ans=0;
        
        int i=0,j=0;
        int ct=0;
        while(j<n)
        {
            if(s[j]=='a' ||s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
                ct++;
            while(j-i+1>k)
            {
                if(s[i]=='a' ||s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                  ct--;
                i++;
            }
            if(j-i+1==k)
            {
                ans=max(ans,ct);
            }
            j++;
        }
        return ans;
    }
};