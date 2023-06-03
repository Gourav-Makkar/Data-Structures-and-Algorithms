//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &v1,vector<int> &v2,vector<int> &v3){
        int s1=0,s2=0,s3=0;
        
        for(auto it:v1)
          s1+=it;
        for(auto it:v2)
          s2+=it;
        for(auto it:v3)
          s3+=it;
         
        int i=0,j=0,k=0; 
        while(s1!=s2 || s2!=s3)
        {
            int mx=max({s1,s2,s3});
            
            if(mx==s1)
            {
                if(i==n1-1)
                  return 0;
                s1-=v1[i++];
            }
            if(mx==s2)
            {
                if(j==n2-1)
                  return 0;
                s2-=v2[j++];
            }
            if(mx==s3)
            {
                if(k==n3-1)
                  return 0;
                s3-=v3[k++];
            }
        }
        return s1;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends