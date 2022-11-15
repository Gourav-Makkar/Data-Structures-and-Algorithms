//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        multiset<long long>s;
        for(int i=0;i<n;i++)
          s.insert(arr[i]);
        long long cost=0;
        while(s.size()!=1)
        {
            multiset<long long>::iterator it1, it2;
            it1=s.begin();
            it2=it1++;
            
            long long first=*it1;
            long long second=*it2;
            
            s.erase(it1);
            s.erase(it2);
            
            long long curr=first+second;
            cost+=curr;
            s.insert(curr);
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends