class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n],in(n,0);
        
        for(auto it:pre)
        {
            in[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans;
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            
            ans.push_back(curr);
            for(auto it:adj[curr])
            {
                in[it]--;
                if(in[it]==0)
                   q.push(it);
            }
        }
        if(ans.size()<n)
            return {};
        return ans;
    }
};