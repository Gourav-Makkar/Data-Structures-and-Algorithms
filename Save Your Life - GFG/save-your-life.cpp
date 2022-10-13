//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
    unordered_map<char, int> ascii;
    for (char c = 'a'; c <= 'z'; c++) {
        ascii[c] = (int)c;
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        ascii[c] = (int)c;
    }

    for (int i = 0; i < n; i++) {
        ascii[x[i]] = b[i];
    }
     
    int mx=INT_MIN;
    int cs=0;
    string ans="";
    string s="";
    
    for(int i=0;i<w.length();i++)
    {
        if(cs+ascii[w[i]] > ascii[w[i]])
        {
            cs+=ascii[w[i]];
            s+=w[i];
        }
        else
        {
            cs=ascii[w[i]];
            s=w[i];
        }
        if(cs>mx)
        {
            mx=cs;
            ans=s;
        }
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends