//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int n1=s.size(),n2=t.size();
        
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(t[j]<65)
            {
                int shift=0;
                while(j<n2 && t[j]<65)
                {
                    shift=shift*10+(t[j]-'0');
                    j++;
                }
                i+=shift;
            }
            else
            {
                if(s[i]!=t[j])
                  return 0;
                i++;
                j++;
            }
        }
        if(i==n1 && j>=n2)
          return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends