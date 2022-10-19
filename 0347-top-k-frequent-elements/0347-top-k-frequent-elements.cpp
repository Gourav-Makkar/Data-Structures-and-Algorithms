class Solution {
public:
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto &it:m)
            v.push_back(it);
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};