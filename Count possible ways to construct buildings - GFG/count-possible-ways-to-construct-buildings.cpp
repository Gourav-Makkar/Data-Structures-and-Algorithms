//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	    vector<int>space(n),building(n);
	    
	    space[0]=1;
	    building[0]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        space[i]=(space[i-1]+building[i-1])%1000000007;
	        building[i]=space[i-1];
	    }
	    long long ans=(space[n-1]+building[n-1]);
	    
	    return (ans*ans)%1000000007;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends