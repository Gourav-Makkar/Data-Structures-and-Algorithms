class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        
        queue<vector<int>>q;
        q.push(rooms[0]);
        vis[0]=1;
        
        while(!q.empty())
        {
            vector<int>v=q.front();
            q.pop();
            
            for(auto it:v)
            {
                if(vis[it]!=1)
                {
                    vis[it]=1;
                    q.push(rooms[it]);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
                return false;
        }
        return true;
    }
};