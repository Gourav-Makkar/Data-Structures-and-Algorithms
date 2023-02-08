//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long int>ans;
      vector<bool>rows(n,false);
      vector<bool>cols(n,false);
      int r=0,c=0;
      long long int fr=n*n;
      
      for(auto it:arr)
      {
          int cr=it[0],cc=it[1];
          
          if(rows[cr-1]==false)
          {
              fr-=(n-c);
              r++;
              rows[cr-1]=true;
          }
          if(cols[cc-1]==false)
          {
              fr-=(n-r);
              c++;
              cols[cc-1]=true;
          }
          ans.push_back(fr);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends