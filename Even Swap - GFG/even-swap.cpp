//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            for(int i=0;i<n;i++)
            {
                int idx=i;
                if(a[idx]%2==0)
                {
                    while(idx<n && a[idx]%2==0)
                      idx++;
                      
                    sort(a.begin()+i,a.begin()+idx,greater<int>());
                    i=idx-1;
                }
                else
                {
                    while(idx<n && a[idx]%2!=0)
                      idx++;
                      
                    sort(a.begin()+i,a.begin()+idx,greater<int>());
                    i=idx-1;
                }
            }
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends