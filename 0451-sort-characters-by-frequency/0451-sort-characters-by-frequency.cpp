class Solution {
public:
    
    static bool cmp(pair<char,int>&a,pair<char,int>&b)
    {
        if(a.second!=b.second)
            return a.second>b.second;
        else
            return a.first<b.first;
    }
    
    string frequencySort(string s) {
        string ans="";
        map<char,int>m;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        vector<pair<char,int>>v;
        for(auto &it:m)
            v.push_back(it);
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<v.size();i++)
        {
            char c=v[i].first;
            int ct=v[i].second;
            while(ct--)
                ans+=c;
        }
        return ans;
    }
};