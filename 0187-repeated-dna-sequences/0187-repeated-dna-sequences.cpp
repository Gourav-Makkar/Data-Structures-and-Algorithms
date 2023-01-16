class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>m;
        vector<string>ans;
        int n=s.size();
        string curr="";
        int i=0,j=0;
        
        while(j<n)
        {
            curr+=s[j];
            if(j-i+1==10)
            {
                m[curr]++;
                curr.erase(curr.begin());
                i++;
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