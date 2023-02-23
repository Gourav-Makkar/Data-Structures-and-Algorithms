class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>temp;
        
        int n=profits.size();
        for(int i=0;i<n;i++)
            temp.push_back({capital[i],profits[i]});
        
        sort(temp.begin(),temp.end());
        
        int i=0,ct=0;
        priority_queue<int>pq;
        
        while(i<n)
        {
            while(i<n && temp[i].first<=w)
            {
                pq.push(temp[i].second);
                i++;
            }
            
            if(pq.empty())
                break;
            
            w+=pq.top();
            ct++;
            pq.pop();
            
            if(ct==k)
                break;
        }
        while(!pq.empty() && ct<k)
        {
            w+=pq.top();
            pq.pop();
            ct++;
        }
        return w;
    }
};