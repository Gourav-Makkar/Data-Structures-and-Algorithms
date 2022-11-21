//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	void helper(int curr,int v,vector<int>temp,vector<vector<int>>&ans)
	{
	    if(curr==0)
	    {
	        ans.push_back(temp);
	        return;
	    }
	    if(v==0)
	      return;
	    if(curr>=v)
	    {
	       temp.push_back(v);
	       helper(curr-v,v,temp,ans);
	       temp.pop_back();
	    }
	    
	   helper(curr,v-1,temp,ans);
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>>ans;
        vector<int>temp;
        helper(n,n,temp,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends