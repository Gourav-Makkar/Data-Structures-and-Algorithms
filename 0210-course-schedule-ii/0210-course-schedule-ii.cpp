class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n],ans;
        
        for(auto it:pre)
            adj[it[1]].push_back(it[0]);
        
        vector<int>indeg(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
                indeg[it]++;
        }
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it:adj[curr])
            {
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        
       if(ans.size()!=n)
           return {};
        return ans;
    }
};