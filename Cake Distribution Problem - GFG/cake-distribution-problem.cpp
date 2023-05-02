//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    bool check(int mid,vector<int>&arr,int k)
    {
        int ct=0,cs=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(cs<mid)
              cs+=arr[i];
            else
            {
                ct++;
                cs=arr[i];
            }
        }
        if(cs>=mid)
          ct++;
        return ct>k;
    }
    
    int maxSweetness(vector<int>& arr, int n, int k) {
       int st=INT_MAX,en=0,ans;
       
       for(auto it:arr)
       {
           st=min(st,it);
           en+=it;
       }
       
       while(st<=en)
       {
           int mid=st+(en-st)/2;
           
           if(check(mid,arr,k))
           {
               ans=mid;
               st=mid+1;
           }
           else
             en=mid-1;
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends