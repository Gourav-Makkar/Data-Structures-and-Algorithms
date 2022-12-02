class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        multiset<int>oc1;
        multiset<int>oc2;
        
        for(int i=0;i<n1;i++)
            m1[word1[i]]++;
        for(int i=0;i<n2;i++)
            m2[word2[i]]++;
        
        if(m1.size()!=m2.size())
            return false;
        
        for(auto it:m1)
        {
            oc1.insert(it.second);
            char c=it.first;
            if(m2[c]==0)
                return false;
        }
        
        for(auto it:m2)
           oc2.insert(it.second);
        
        if(oc1!=oc2)
            return false;
        
        return true;
    }
};