class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>>q;
        int r=maze.size();
        int c=maze[0].size();
        
        vector<int>v;
        v.push_back(entrance[0]);
        v.push_back(entrance[1]);
        v.push_back(0);
        maze[entrance[0]][entrance[1]]='+';
        q.push(v);
        int ans=1e9;
        
        while(!q.empty())
        {
            vector<int>v=q.front();
            q.pop();
            int cr=v[0];
            int cc=v[1];
            int ct=v[2];
            if(cr!=entrance[0] || cc!=entrance[1])
            {
                if(cr==r-1 || cr==0 || cc==0 || cc==c-1)
                    ans=min(ans,ct);
            }
            if(cr>0 && maze[cr-1][cc]!='+')
            {
                vector<int>temp;
                temp.push_back(cr-1);
                temp.push_back(cc);
                temp.push_back(ct+1);
                maze[cr-1][cc]='+';
                q.push(temp);
            }
            
            if(cr<r-1 && maze[cr+1][cc]!='+')
            {
                vector<int>temp;
                temp.push_back(cr+1);
                temp.push_back(cc);
                temp.push_back(ct+1);
                maze[cr+1][cc]='+';
                q.push(temp);
            }
            
            if(cc>0 && maze[cr][cc-1]!='+')
            {
                vector<int>temp;
                temp.push_back(cr);
                temp.push_back(cc-1);
                temp.push_back(ct+1);
                maze[cr][cc-1]='+';
                q.push(temp);
            }
            if(cc<c-1 && maze[cr][cc+1]!='+')
            {
                vector<int>temp;
                temp.push_back(cr);
                temp.push_back(cc+1);
                temp.push_back(ct+1);
                maze[cr][cc+1]='+';
                q.push(temp);
            }
                
        }
        if(ans>=1e9)
            return -1;
        return ans;
    }
};