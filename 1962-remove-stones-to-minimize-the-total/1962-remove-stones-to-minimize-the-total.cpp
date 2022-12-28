class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<double>pq;
        
        for(auto x:piles)
            pq.push(x);
        
        while(k--)
        {
            double val=pq.top();
            pq.pop();
            pq.push(ceil(val/2));
        }
        
        double ans=0;
        while(pq.size()!=0)
        {
            ans+=pq.top();
            pq.pop();
        }
        return int(ans);
    }
};