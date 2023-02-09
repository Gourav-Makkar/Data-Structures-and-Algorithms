class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>s[26];
        long long ans=0;
        
        for(auto it:ideas)
            s[it[0]-'a'].insert(it.substr(1));
        
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                long long ct1=0,ct2=0;
                for(auto it:s[i])
                {
                    if(s[j].find(it)==s[j].end())
                        ct1++;
                }
                for(auto it:s[j])
                {
                    if(s[i].find(it)==s[i].end())
                        ct2++;
                }
                ans+=ct1*ct2;
            }
        }
        return 2*ans;
    }
};