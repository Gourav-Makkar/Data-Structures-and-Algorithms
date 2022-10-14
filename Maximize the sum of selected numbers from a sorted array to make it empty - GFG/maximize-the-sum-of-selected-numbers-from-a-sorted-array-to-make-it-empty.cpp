//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:

    int maximizeSum(int arr[], int n) 
    {
        // Complete the function
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(m.find(arr[i])==m.end())
              continue;
            ans+=arr[i];
            m[arr[i]]--;
            if(m[arr[i]]==0)
              m.erase(arr[i]);
            if(m.find(arr[i]-1)!=m.end())
            {
                m[arr[i]-1]--;
                if(m[arr[i]-1]==0)
                 m.erase(arr[i]-1);
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends