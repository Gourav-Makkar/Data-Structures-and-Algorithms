//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string small="",large="";
        for(int i=0;i<n;i++)
        {
            if(str[i]<97)
              small+=str[i];
              
            else
              large+=str[i];
        }
        sort(small.begin(),small.end());
        sort(large.begin(),large.end());
        
        int i=0,j=0,k=0;
        int n1=small.size(),n2=large.size();
        string ans="";
        for(int i=0;i<n;i++)
          ans+='.';
        
        while(i<n1 && j<n2)
        {
            if(str[k]<97)
              ans[k++]=small[i++];
            else
              ans[k++]=large[j++];
        }
        while(i<n1)
          ans[k++]=small[i++];
        while(j<n2)
          ans[k++]=large[j++];
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends