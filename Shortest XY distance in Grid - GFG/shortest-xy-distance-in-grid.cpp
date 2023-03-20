//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X')
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty())
        {
            int dis=q.front().first;
            int cr=q.front().second.first;
            int cc=q.front().second.second;
            
            q.pop();
            
            if(grid[cr][cc]=='Y')
              return dis;
            
            vector<int>temp{-1,0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=cr+temp[i];
                int nc=cc+temp[i+1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({dis+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends