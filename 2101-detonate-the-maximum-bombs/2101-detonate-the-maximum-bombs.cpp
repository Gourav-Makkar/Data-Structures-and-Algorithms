class Solution {
public:
    
    long long findDis(int x1,int y1,int x2,int y2)
    {
        return pow(x2-x1,2) + pow(y2-y1,2);
    }
    
    
    int dfs(vector<int>adj[],int curr,vector<int>&vis)
    {
        vis[curr]=1;
        int ct=1;
        
        for(auto it:adj[curr])
        {
            if(vis[it]!=1)
                ct+=dfs(adj,it,vis);
        }
        
        return ct;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double dis=sqrt(findDis(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1]));
                
                if(bombs[i][2]>=dis)
                    adj[i].push_back(j);
                
                if(bombs[j][2]>=dis)
                    adj[j].push_back(i);
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,0);
            ans=max(ans,dfs(adj,i,vis));
        }
        
        return ans;
    }
};