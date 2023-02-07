//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
           int first_neg=-1,negct=0,i=0,j=0,ans=0;
           
           while(j<n)
           {
               if(arr[j]<0)
               {
                   negct++;
                   if(first_neg==-1)
                     first_neg=j;
               }
               
               if(arr[j]==0)
               {
                   i=j+1;
                   first_neg=-1;
                   negct=0;
                   j++;
                   continue;
               }
                   
               if(negct%2==0)
                 ans=max(ans,j-i+1);
               else
                 ans=max(ans,j-first_neg);
               
               j++;
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends