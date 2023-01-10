//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void helper(int cr,int cc,vector<vector<int>>&m,string curr,int n,vector<string>&ans)
    {
        if(cr<0 || cr==n || cc<0 || cc==n || m[cr][cc]==0)
          return;
          
        if(cr==n-1 && cc==n-1)
        {
            ans.push_back(curr);
            return;
        }
        
        m[cr][cc]=0;
        
        curr.push_back('U');
        helper(cr-1,cc,m,curr,n,ans);
        curr.pop_back();
        
        curr.push_back('R');
        helper(cr,cc+1,m,curr,n,ans);
        curr.pop_back();
        
        curr.push_back('D');
        helper(cr+1,cc,m,curr,n,ans);
        curr.pop_back();
        
        curr.push_back('L');
        helper(cr,cc-1,m,curr,n,ans);
        curr.pop_back();
        
        m[cr][cc]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0]==0)
          return ans;
          
        string curr="";
        
        helper(0,0,m,curr,n,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends