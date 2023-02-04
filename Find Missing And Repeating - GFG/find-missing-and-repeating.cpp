//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int txor=0;
        int *res=new int[2];
        for(int i=1;i<=n;i++)
          txor=txor^i;
         
        for(int i=0;i<n;i++)
          txor=txor^arr[i];
          
        map<int,int>m1,m2;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]&txor)
              m1[arr[i]]++;
            else
              m2[arr[i]]++;
        }
        int rep;
        for(auto it:m1)
        {
            if(it.second==2)
              rep=it.first;
        }
        for(auto it:m2)
        {
            if(it.second==2)
              rep=it.first;
        }
        res[0]=rep;
        res[1]=txor^rep;
        
        return res;
    } 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends