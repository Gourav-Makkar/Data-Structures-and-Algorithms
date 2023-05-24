class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>temp;
        
        for(int i=0;i<n;i++)
          temp.push_back({nums2[i],nums1[i]});
        
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        long long cs=0,ans=INT_MIN;
        
        int i=0;
        while(i<n)
        {
            cs+=temp[i].second;
            pq.push(temp[i].second);
            
            if(pq.size()==k)
            {
                ans=max(ans,cs*temp[i].first);
                cs-=pq.top();
                pq.pop();
            }
            i++;
        }
        return ans;
    }
};