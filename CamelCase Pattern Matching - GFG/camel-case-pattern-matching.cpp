//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string>ans;
        
        for(int i=0;i<N;i++)
        {
            string s=Dictionary[i];
            
            string abbr="";
            for(int i=0;i<s.size();i++)
            {
                if(s[i]>=65 && s[i]<=90)
                  abbr+=s[i];
            }
            
            int n=Pattern.size();
            if(abbr.size()>=n)
            {
                bool flag=true;
                for(int i=0;i<n;i++)
                {
                    if(abbr[i]!=Pattern[i])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                  ans.push_back(s);
            }
        }
        if(ans.size()==0)
          return {"-1"};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends