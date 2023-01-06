class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        int n=s.length();
        
        if(n<=10)
            return ans;
        string curr="";
        int j=0;
        unordered_map<string,int>m;
        
        while(j<n)
        {
            curr+=s[j];
            if(curr.size()==10)
            {
                m[curr]++;
                curr.erase(curr.begin());
            }
            j++;
        }
        for(auto it:m)
        {
            if(it.second>1)
                ans.push_back(it.first);
        }
        return ans;
    }
};