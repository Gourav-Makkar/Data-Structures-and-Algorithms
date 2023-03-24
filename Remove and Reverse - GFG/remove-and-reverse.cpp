//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        string s1="",s2="";
        int n=s.size(),ct=0;
        bool flag=true;
        
        unordered_map<char,int>m;
        for(auto it:s)
          m[it]++;
        
        int i=0,j=n-1;
        while(i<=j)
        {
          if(flag)
          {
              if(m[s[i]]>1)
              {
                  m[s[i]]--;
                  flag=false;
                  ct++;
              }
              else
                s1+=s[i];
    
              i++;
          }
          else
          {
              if(m[s[j]]>1)
              {
                  m[s[j]]--;
                  flag=true;
                  ct++;
              }
              else
                s2+=s[j];
              
              j--;
          }
        }
        reverse(s2.begin(),s2.end());
        string ans=s1+s2;
        
        if(ct%2!=0)
          reverse(ans.begin(),ans.end());
          
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends