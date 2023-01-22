//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &arr) {
        // code here
        int sum=0;
        for(int i=1;i<n;i++)
        {
            arr[i]+=arr[i-1];
        }
        sum=arr[n-1];
        vector<int>factors;
        
        for(int i=1;i*i<=sum;i++)
        {
            if(sum%i==0)
            {
                factors.push_back(i);
                factors.push_back(sum/i);
            }
        }
        int ans=1;
        
        for(auto it:factors)
        {
            int ct=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]%it==0)
                  ct++;
            }
            if(ct>=k)
              ans=max(ans,it);
        }
        return ans;
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
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends