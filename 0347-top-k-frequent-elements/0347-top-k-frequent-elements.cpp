class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>ans;
        
        for(auto it:nums)
            m[it]++;
        
        vector<pair<int,int>>temp;
        
        for(auto it:m)
            temp.push_back({it.second,it.first});
        
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        
        for(int i=0;i<k;i++)
            ans.push_back(temp[i].second);
        return ans;
    }
};