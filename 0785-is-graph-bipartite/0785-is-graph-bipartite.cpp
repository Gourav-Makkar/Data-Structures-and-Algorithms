class Solution {
public:
    
    bool bfs(vector<vector<int>>&graph,vector<int>&col,int curr)
    {
        queue<int>q;
        q.push(curr);
        col[curr]=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int c=col[node];
                
            for(auto it:graph[node])
            {
                if(col[it]==c)
                    return false;
                if(col[it]==-1)
                {
                    col[it]=(c==0)?1:0;
                    q.push(it);
                }
            }
        }
        return true;
    }
    
    
    bool dfs(vector<vector<int>>&graph,vector<int>&col,int curr,int c)
    {
        col[curr]=c;
        
        for(auto it:graph[curr])
        {
            if(col[it]==c)
                return false;
            if(col[it]==-1)
            {
                if(dfs(graph,col,it,!c)==false)
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(dfs(graph,col,i,0)==false)
                    return false;
            }
        }
        return true;
    }
};