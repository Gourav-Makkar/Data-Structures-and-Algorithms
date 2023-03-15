//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    
    int find1(int pos,string &temp,string &s2)
    {
        int m=s2.size();
        int ct=0;
        for(int i=pos;i<pos+m;i++)
        {
            if(temp[i]!=s2[i-pos])
            {
                ct++;
                temp[i]=s2[i-pos];
            }
        }
        return ct;
    }
    
    int find2(string s,int st,int en)
    {
        int n=s.size();
        int i=0,j=n-1,ct=0;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                if(i>=st && i<=en && j>=st && j<=en)
                  return 1e9;
                ct++;
            }
            i++;
            j--;
        }
        return ct;
    }
    
    int specialPalindrome(string s1, string s2){
        int n=s1.size(),m=s2.size(),ans=INT_MAX;
        
        for(int i=0;i<=n-m;i++)
        {
            string temp=s1;
            int ct=find1(i,temp,s2);
            
            ct+=find2(temp,i,i+m-1);
            ans=min(ans,ct);
        }
        if(ans>=1e9)
          return -1;
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends