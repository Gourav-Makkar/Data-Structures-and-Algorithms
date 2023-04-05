//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
       int mx=INT_MIN,ans=0;
       
       for(auto it:arr)
         mx=max(mx,it);
       
       unordered_map<int,int>m;
       
       for(int i=0;i<n;i++)
       {
           int num=arr[i];
           if(m[num]>1)
             continue;
             
           for(int curr=num;curr<=mx;curr+=num)
             m[curr]++;
       }
       
       for(int i=0;i<n;i++)
       {
           if(m[arr[i]]>1)
             ans++;
       }
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends