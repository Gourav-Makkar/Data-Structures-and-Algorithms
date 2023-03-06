//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
       vector<int>temp;
       
       while(n>0)
       {
           temp.push_back(n%2);
           n=n/2;
       }
       reverse(temp.begin(),temp.end());
       
       int ct=0;
       for(int i=0;i<temp.size();i++)
       {
           if(temp[i]==1)
           {
               ct++;
               if(ct==3)
                 temp[i]=0;
           }
           if(temp[i]==0)
             ct=0;
       }
       int ans=0;
       int val=1;
       for(int i=temp.size()-1;i>=0;i--)
       {
           if(temp[i]==1)
             ans+=val;
           
           val*=2;
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

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends