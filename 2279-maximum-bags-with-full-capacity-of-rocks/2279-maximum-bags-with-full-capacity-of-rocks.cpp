class Solution {
public:
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return (a.first-a.second) < (b.first-b.second);
    }
    
    int maximumBags(vector<int>& cap, vector<int>& rocks, int r) {
        int n=cap.size(),ans=0;
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++)
            v.push_back({cap[i],rocks[i]});
        
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<n;i++)
        {
            int temp=v[i].first-v[i].second;
            if(r>=temp)
            {
                r=r-temp;
                ans++;
            }
            else
                break;
        }
        
        return ans;
    }
};