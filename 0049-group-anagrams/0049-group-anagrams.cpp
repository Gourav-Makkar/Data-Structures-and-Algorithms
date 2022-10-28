class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();
        vector<string>temp=strs;
        unordered_map<string,vector<string>>m;
        for(int i=0;i<n;i++)
        {
            sort(temp[i].begin(),temp[i].end());
            if(m.count(temp[i]))
             m[temp[i]].push_back(strs[i]);
            else
                m[temp[i]]={strs[i]};
                
        }
        for(auto i:m)
            ans.push_back(i.second);
        return ans;
       
    }
};