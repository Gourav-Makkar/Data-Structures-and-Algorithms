//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int findPar(int curr,vector<int>&par)
    {
        if(curr==par[curr])
          return curr;
        
        return par[curr]=findPar(par[curr],par);
    }
  
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m) {
        
        vector<int>size(n+1,1);
        vector<int>par(n+1);
        vector<string>ans;
        
        for(int i=0;i<=n;i++)
          par[i]=i;
          
        for(int i=0;i<n;i++)
        {
            int u=mix[i][0],v=mix[i][1];
            int pu=findPar(u,par);
            int pv=findPar(v,par);
            
            bool flag=true;
            for(int i=0;i<m;i++)
            {
                int f=danger[i][0];
                int s=danger[i][1];
                
                int pf=findPar(f,par);
                int ps=findPar(s,par);
                
                if(pf==pu && ps==pv || pf==pv && ps==pu)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ans.push_back("Yes");
                if(size[pu]<size[pv])
                 {
                     size[pv]+=size[pu];
                     par[pu]=pv;
                 }
                 else
                 {
                     size[pu]+=size[pv];
                     par[pv]=pu;
                }
             }
            
            else
            {
                ans.push_back("No");
            }
            
        }
        return ans;                              
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends