//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string>st;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==']')
             {
                 string t="";
                 t+=s[i];
                 st.push(t);
             }
            else if(s[i]>=97 && s[i]<=122)
              {
                 string t="";
                 t+=s[i];
                 st.push(t);
              }
            else if(s[i]=='[')
            {
                string temp="";
                while(st.top()!="]")
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(temp);
            }
            else if(s[i]>=48 && s[i]<=57)
            {
                string n="";
                while(i>=0 && s[i]>=48 && s[i]<=57)
                {
                    n+=s[i];
                    i--;
                }
                reverse(n.begin(),n.end());
                int x=stoi(n);
                string temp="";
                string t=st.top();
                st.pop();
                for(int i=1;i<=x;i++)
                {
                    temp+=t;
                }
                st.push(temp);
                i++;
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends