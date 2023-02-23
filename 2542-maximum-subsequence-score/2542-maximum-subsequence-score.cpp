class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>temp;
        
        int n=nums1.size();
        for(int i=0;i<n;i++)
           temp.push_back({nums2[i],nums1[i]});
        
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        int j=0;
        long long cs=0,ans=INT_MIN;
        
        while(j<n)
        {
            cs+=temp[j].second;
            pq.push(temp[j].second);
            if(pq.size()==k)
            {
                ans=max(ans,cs*temp[j].first);
                cs-=pq.top();
                pq.pop();
            }
            j++;
        }
        return ans;
    }
};