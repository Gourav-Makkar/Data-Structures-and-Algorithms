//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int n=s.size(),ans=0,cs=0,i=0;
        
        unordered_map<int,int>m;
        
        while(i<n)
        {
            if(s[i]>='A' && s[i]<='Z')
              cs+=-1;
            
            if(s[i]>='a' && s[i]<='z')
              cs+=1;
              
            if(cs==0)
              ans++;
            
            if(m.find(cs)!=m.end())
              ans+=m[cs];
            
            m[cs]++;
            i++;
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends