class Solution {
public:
    
    static bool cmp(pair<pair<int,int>,long long>&a,pair<pair<int,int>,long long>&b)
    {
         return a.second<b.second;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        
        vector<pair<pair<int,int>,long long>>temp;
        for(auto it:points)
        {
            long long d=it[0]*it[0] + it[1]*it[1];
            temp.push_back({{it[0],it[1]},d});
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        for(int i=0;i<k;i++)
            ans.push_back({temp[i].first.first,temp[i].first.second});
        
        return ans;
    }
};