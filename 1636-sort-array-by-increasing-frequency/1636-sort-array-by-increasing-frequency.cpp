class Solution {
public:
    
static bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    if(a.second==b.second)
       return a.first>b.first;
    return a.second < b.second;
}
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>>temp;
        for(auto it:m)
            temp.push_back(it);
        
        sort(temp.begin(),temp.end(),cmp);
        vector<int>ans;
        for(int i=0;i<temp.size();i++)
        {
            int val=temp[i].first;
            int ct=temp[i].second;
            for(int i=0;i<ct;i++)
                ans.push_back(val);
        }
        return ans;
    }
};