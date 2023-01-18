class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            q.push({tickets[i],i});
        }
        int ans=0;
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            p.first--;
            q.pop();
            ans++;
            if(p.first==0)
            {
                if(p.second==k)
                    return ans;
            }
            else
            {
                q.push({p.first,p.second});
            }
        }
        return ans;
    }
};