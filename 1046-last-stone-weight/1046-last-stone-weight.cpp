class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(auto it:stones)
            pq.push(it);
        
        while(pq.size()>=2)
        {
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            
            if(f!=s)
                pq.push(f-s);
        }
        if(pq.size()==0)
            return 0;
        return pq.top();
    }
};