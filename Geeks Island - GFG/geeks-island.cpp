//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    void dfs(int cr,int cc,vector<vector<int>>&mat,vector<vector<int>>&vis,int n,int m)
    {
        if(vis[cr][cc])
          return;
        vis[cr][cc]=1;
        
        if(cr>0 && mat[cr-1][cc]>=mat[cr][cc])
          dfs(cr-1,cc,mat,vis,n,m);
          
        if(cc<m-1 && mat[cr][cc+1]>=mat[cr][cc])
          dfs(cr,cc+1,mat,vis,n,m);
        
        if(cr<n-1 && mat[cr+1][cc]>=mat[cr][cc])
          dfs(cr+1,cc,mat,vis,n,m);
        
        if(cc>0 && mat[cr][cc-1]>=mat[cr][cc])
          dfs(cr,cc-1,mat,vis,n,m);
    }
    
    int water_flow(vector<vector<int>> &mat,int n,int m){
        
       vector<vector<int>>ind(n,vector<int>(m,0));
       vector<vector<int>>ara(n,vector<int>(m,0));
       
       for(int i=0;i<n;i++)
       {
           dfs(i,0,mat,ind,n,m);
           dfs(i,m-1,mat,ara,n,m);
       }
       
       for(int i=0;i<m;i++)
       {
           dfs(0,i,mat,ind,n,m);
           dfs(n-1,i,mat,ara,n,m);
       }
       
       int ans=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(ind[i][j]==1 && ara[i][j]==1)
                 ans++;
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
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends