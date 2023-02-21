//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>mat(n,vector<int>(m,0));
        mat[x-1][y-1]=1;
        
        q.push({0,{x-1,y-1}});
        int ans=0;
        while(!q.empty())
        {
            int mv=q.front().first;
            int cr=q.front().second.first;
            int cc=q.front().second.second;
            
            q.pop();
            
            ans=max(ans,mv);
            
            if(cr>0 && mat[cr-1][cc]==0)
            {
                mat[cr-1][cc]=1;
                q.push({mv+1,{cr-1,cc}});
            }
            
            if(cc<m-1 && mat[cr][cc+1]==0)
            {
                mat[cr][cc+1]=1;
                q.push({mv+1,{cr,cc+1}});
            }
            
            if(cr<n-1 && mat[cr+1][cc]==0)
            {
                mat[cr+1][cc]=1;
                q.push({mv+1,{cr+1,cc}});
            }
            
            if(cc>0 && mat[cr][cc-1]==0)
            {
                mat[cr][cc-1]=1;
                q.push({mv+1,{cr,cc-1}});
            }
        }
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
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends