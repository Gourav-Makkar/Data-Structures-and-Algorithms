class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();
        vector<string>temp=strs;
        unordered_map<string,vector<int>>m;
        for(int i=0;i<n;i++)
        {
            sort(temp[i].begin(),temp[i].end());
            if(m.count(temp[i]))
             m[temp[i]].push_back(i);
            else
                m[temp[i]]={i};
                
        }
        
        vector<string>curr;
        for(auto it:m)
        {
            vector<int>pos=it.second;
            for(int i=0;i<pos.size();i++)
            {
                curr.push_back(strs[pos[i]]);
            }
            ans.push_back(curr);
            curr.clear();
        }
        
        return ans;
    }
};