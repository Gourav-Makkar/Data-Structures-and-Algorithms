//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<long long>st;
        vector<long long>nextGr(n);
        
        nextGr[n-1]=-1;
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<=arr[i])
              st.pop();
            
            long long ele=(st.empty())?-1:st.top();
            nextGr[i]=ele;
            
            st.push(arr[i]);
        }
        return nextGr;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends