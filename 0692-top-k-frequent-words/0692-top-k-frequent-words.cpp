class Solution {
public:
    
    static bool cmp(pair<string,int>&a,pair<string,int>&b)
    {
        if(a.second!=b.second)
            return a.second>b.second;
        else
            return a.first<b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        
        vector<pair<string,int>>v;
        for(auto &it: m)
            v.push_back(it);
        
        sort(v.begin(),v.end(),cmp);
            
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};