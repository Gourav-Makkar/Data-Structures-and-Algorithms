//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ct=0;
    void merge(long long arr[],int st,int mid,int en)
    {
        int n1=mid-st+1;
        int n2=en-mid;
        
        long long a1[n1],a2[n2];
        
        for(int i=0;i<n1;i++)
        {
            a1[i]=arr[st+i];
        }
        for(int i=0;i<n2;i++)
        {
            a2[i]=arr[mid+1+i];
        }
        
        int i=0,j=0,k=st;
        
        while(i<n1 && j<n2)
        {
            if(a1[i]<=a2[j])
              arr[k++]=a1[i++];
            else
              {
                  ct+=n1-i;
                  arr[k++]=a2[j++];
              }
        }
        
        while(i<n1)
          arr[k++]=a1[i++];
          
        while(i<n2)
          arr[k++]=a2[j++];
    }
    
    void mergeSort(long long arr[],int st,int en)
    {
        if(st<en)
        {
            int mid=st+(en-st)/2;
            
            mergeSort(arr,st,mid);
            mergeSort(arr,mid+1,en);
            
            merge(arr,st,mid,en);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return ct;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends