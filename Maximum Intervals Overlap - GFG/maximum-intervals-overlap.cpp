//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int st[], int en[], int n)
	{
	   vector<int>temp(100002,0);
	   
	   for(int i=0;i<n;i++)
	   {
	       temp[st[i]]++;
	       temp[en[i]+1]--;
	   }
	   
	   for(int i=1;i<temp.size();i++)
	     temp[i]+=temp[i-1];
	     
	   int tim,guests=INT_MIN;
	   
	   for(int i=1;i<temp.size();i++)
	   {
	       if(temp[i]>guests)
	       {
	           guests=temp[i];
	           tim=i;
	       }
	   }
	   return {guests,tim};
	}

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends