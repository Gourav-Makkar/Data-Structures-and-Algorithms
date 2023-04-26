class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int>indeg(num,0);
        vector<int>adj[num];
        vector<int>ans;
        
        queue<int>q;
        
        for(auto it:pre)
        {
            indeg[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<num;i++)
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
        return ans.size()==num;
    }
};