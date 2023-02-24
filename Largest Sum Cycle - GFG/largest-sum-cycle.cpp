//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  void dfs(int curr,vector<int>&edge,vector<int>&vis,vector<int>&pathVis,long long &ans)
    {
        vis[curr]=1;
        pathVis[curr]=1;
        
        int adj=edge[curr];
        if(adj!=-1)
        {
            if(vis[adj]==0)
              dfs(adj,edge,vis,pathVis,ans);
            
            else if(pathVis[adj])
            {
                int node=adj;
                long long cs=0;
                do{
                    cs+=node;
                    node=edge[node];
                }while(node!=adj);
                
                ans=max(ans,cs);
            }
        }
        pathVis[curr]=0;
    }
  
  long long largestSumCycle(int n, vector<int> edge)
  {
     long long ans=-1;
       
     vector<int>vis(n,0),pathVis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                dfs(i,edge,vis,pathVis,ans);
            }
        }
        return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends