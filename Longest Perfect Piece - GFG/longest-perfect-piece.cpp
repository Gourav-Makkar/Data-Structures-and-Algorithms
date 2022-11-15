//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        map<int,int>m;
        int i=0,j=0;
        int ans=1;
        while(j<N)
        {
            m[arr[j]]++;
            if(m.rbegin()->first - m.begin()->first <=1)
              ans=max(ans,j-i+1);
            else
            {
                while(m.rbegin()->first - m.begin()->first >1)
                {
                    m[arr[i]]--;
                    if(m[arr[i]]==0)
                      m.erase(arr[i]);
                    i++;
                }
                ans=max(ans,j-i+1);
            }
            j++;
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
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends