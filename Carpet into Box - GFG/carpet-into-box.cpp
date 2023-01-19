//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        long long lc=A,bc=B,lb=C,bb=D;
        
        int ct1=0,ct2=0;
        
        while(lc>lb)
        {
            ct1++;
            lc=lc/2;
        }
        while(bc>bb)
        {
            ct1++;
            bc=bc/2;
        }
        
        lc=B,bc=A;
        while(lc>lb)
        {
            ct2++;
            lc=lc/2;
        }
        while(bc>bb)
        {
            ct2++;
            bc=bc/2;
        }
        return min(ct1,ct2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends