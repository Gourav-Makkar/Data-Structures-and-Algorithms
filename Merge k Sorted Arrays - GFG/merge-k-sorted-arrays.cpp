//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    
    void merge(vector<int>v1,vector<int>v2,int n1,int n2,vector<int>&ans)
    {
        int i=0,j=0,k=0;
        
        while(i<n1 && j<n2)
        {
            if(v1[i]<v2[j])
            {
                ans[k++]=v1[i++];
            }
            else
            {
                ans[k++]=v2[j++];
            }
        }
        while(i<n1)
         ans[k++]=v1[i++];
        
        while(j<n2)
         ans[k++]=v2[j++];
    }
    
    void mergeArray(vector<vector<int>>&arr,int st,int en,vector<int>&ans,int k)
    {
        if(st==en)
        {
            for(int i=0;i<k;i++)
               ans[i]=arr[st][i];
            return;
        }
        
        if(en-st==1)
        {
            merge(arr[st],arr[en],k,k,ans);
            return;
        }
        
        vector<int> op1(k * (((st+en)/2) - st +1)),op2(k * (en - ((st+en)/2)));
        
        mergeArray(arr,st,(st+en)/2,op1,k);
        mergeArray(arr,((st+en)/2) + 1,en,op2,k);
        
        merge(op1,op2,k * (((st+en)/2) - st +1),k * (en - ((st+en)/2)),ans);
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<int>ans(k*k);
        
        mergeArray(arr,0,k-1,ans,k);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends