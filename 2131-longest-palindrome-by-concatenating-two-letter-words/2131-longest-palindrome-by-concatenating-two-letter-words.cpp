class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int>m;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            m[words[i]]++;
        }
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            string rev=s;
            reverse(rev.begin(),rev.end());
            if(s!=rev && m[s]>0 && m[rev]>0)
            {
                ans+=4;
                m[s]--;
                m[rev]--;
            }
            else if(s==rev && m[s]>1)
            {
                ans+=4;
                m[s]=m[s]-2;
            }
            else if(s==rev && m[s]==1 && !flag)
            {
                ans+=2;
                m[s]--;
                flag=true;
            }
        }
        
        
        return ans;
    }
};