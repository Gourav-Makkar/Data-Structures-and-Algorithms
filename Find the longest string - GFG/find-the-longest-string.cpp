//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        string ans="";
        sort(words.begin(),words.end());
        
        unordered_set<string>s(words.begin(),words.end());
        
        for(auto temp:words)
        {
            string curr="";
            bool flag=true;
            for(int i=0;i<temp.size();i++)
            {
                curr+=temp[i];
                if(s.find(curr)==s.end())
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                if(curr.size()>ans.size())
                  ans=curr;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends