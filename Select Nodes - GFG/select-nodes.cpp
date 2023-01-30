//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int ans=0; 
    bool helper(int curr,int parent,vector<int>adj[])
    {
        bool to_light=false;
        for(auto it:adj[curr])
        {
            if(it!=parent)
            {
                bool child=helper(it,curr,adj);
                
                if(child==false)
                  to_light=true;
            }
        }
        if(to_light)
          ans++;
          
        return to_light;
    }
  
    int countVertex(int N, vector<vector<int>>edges){
        vector<int>adj[N+1];
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        helper(1,-1,adj);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends