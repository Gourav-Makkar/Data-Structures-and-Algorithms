class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        
        int n=nums.size();
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        
        for(int i=1;i<n;i++)
        {
            if(v[i-1].first==v[i].first && abs(v[i-1].second - v[i].second)<=k )
                return true;
        }
        return false;
    }
};