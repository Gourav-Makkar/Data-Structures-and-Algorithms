//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
      int ans,mx=INT_MIN;
      vector<int>weight(n,0);
      for(int i=0;i<n;i++)
      {
          int pt=edge[i];
          if(pt!=-1)
            weight[pt]+=i;
      }
      for(int i=0;i<n;i++)
      {
          if(weight[i]>=mx)
          {
              ans=i;
              mx=weight[i];
          }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
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
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends