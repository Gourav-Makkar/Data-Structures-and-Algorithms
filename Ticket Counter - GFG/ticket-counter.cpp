//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int k) {
        int i=1,j=N;
        bool flag=true;
        
        while(true)
        {
            if(flag)
            {
                if(i+k>j)
                  return j;
                i+=k;
            }
            else
            {
                if(j-k<i)
                  return i;
                j-=k;
            }
            flag=!flag;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends