class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<n;i++)
            m[arr[i]].push_back(i);
        
        queue<int>q;
        vector<int>vis(n,0);
        vis[0]=1;
        q.push(0);
        int ans=0;
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int curr=q.front();
                q.pop();
                
                if(curr==n-1)
                    return ans;
                
                if(curr-1>=0 && !vis[curr-1])
                {
                    vis[curr-1]=1;
                    q.push(curr-1);
                }
                
                if(curr+1<n && !vis[curr+1])
                {
                    vis[curr+1]=1;
                    q.push(curr+1);
                }
                
                for(auto it:m[arr[curr]])
                {
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
                m[arr[curr]].clear();
            }
            ans++;
        }
        return ans;
    }
};