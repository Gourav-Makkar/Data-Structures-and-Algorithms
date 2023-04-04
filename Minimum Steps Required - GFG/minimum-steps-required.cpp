//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int n=str.size();
    int cta=0,ctb=0;
    
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a')
        {
            cta++;
            while(i<n && str[i]=='a')
              i++;
            i--;
        }
        if(str[i]=='b')
        {
            ctb++;
            while(i<n && str[i]=='b')
              i++;
            i--;
        }
    }
    return min(cta,ctb)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends