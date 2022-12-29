class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        int n=tasks.size();
        
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(),tasks.end());
        
        long long ct=tasks[0][0];
        int idx=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        while(!pq.empty() || idx<n)
        {
            while(idx<n && tasks[idx][0]<=ct)
            {
                pq.push({tasks[idx][1],tasks[idx][2]});
                idx++;
            }
            if(pq.empty())
                ct=tasks[idx][0];
            else
            {
                pair<int,int>p=pq.top();
                pq.pop();
                ans.push_back(p.second);
                ct+=p.first;
            }
        }
        
        return ans;
    }
};