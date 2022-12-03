class Solution {
public:
    
    static bool cmp(pair<char,int>&a,pair<char,int>&b)
    {
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char,int>m;
        int n=s.size();
        for(int i=0;i<n;i++)
            m[s[i]]++;
        
        vector<pair<char,int>>temp;
        
        for(auto it:m)
            temp.push_back(it);
        
        sort(temp.begin(),temp.end(),cmp);
        
        string ans="";
        for(int i=0;i<temp.size();i++)
        {
            int size=temp[i].second;
            while(size>0)
            {
                ans+=temp[i].first;
                size--;
            }
        }
        
        return ans;
    }
};