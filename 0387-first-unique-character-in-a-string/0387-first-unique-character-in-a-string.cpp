class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        vector<int>v(26,0);
        queue<pair<char,int>>q;
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
            q.push({s[i],i});
        }
        
        while(!q.empty())
        {
            pair<char,int>p=q.front();
            char c=p.first;
            if(v[c-'a']==1)
                return p.second;
            q.pop();
        }
        return -1;
    }
};