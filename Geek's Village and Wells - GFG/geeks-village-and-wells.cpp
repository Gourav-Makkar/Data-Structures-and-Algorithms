//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>>ans(n,vector<int>(m,-1));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='W')
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>temp={-1,0,1,0,-1};
        while(!q.empty())
        {
            int cr=q.front().first.first;
            int cc=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            
            ans[cr][cc]=dis;
            
            
            for(int i=1;i<5;i++)
            {
                int nr=cr+temp[i-1];
                int nc=cc+temp[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=1 && (c[nr][nc]=='.' || c[nr][nc]=='H'))
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},dis+1});
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='.' || c[i][j]=='N')
                  ans[i][j]=0;
                
                if(c[i][j]=='H' && ans[i][j]!=-1)
                  ans[i][j]*=2;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends