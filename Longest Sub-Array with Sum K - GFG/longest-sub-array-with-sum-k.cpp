//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int i=0,cs=0,ans=0;
        unordered_map<int,int>m;
        while(i<n)
        {
            cs+=a[i];
            if(cs==k)
              ans=i+1;
            
            if(m.find(cs-k)!=m.end())
              ans=max(ans,i-m[cs-k]);
            
            if(m.find(cs)==m.end())
              m[cs]=i;
              
            i++;
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends