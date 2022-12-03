//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool check(int dis,vector<int>&stalls,int cows)
    {
        int prev=stalls[0];
        cows--;
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-prev>=dis)
            {
                prev=stalls[i];
                cows--;
                if(cows==0)
                  return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int ans;
        sort(stalls.begin(),stalls.end());
        
        int st=1,en=stalls[n-1]-stalls[0];
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(mid,stalls,k))
             {
                ans=mid;
                st=mid+1;
             }
             else
               en=mid-1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends