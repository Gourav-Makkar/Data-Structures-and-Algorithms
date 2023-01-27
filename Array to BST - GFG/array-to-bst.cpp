//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void helper(vector<int>&nums,int st,int en,vector<int>&ans)
    {
        if(st>en)
          return;
        int mid=st+(en-st)/2;
        ans.push_back(nums[mid]);
        helper(nums,st,mid-1,ans);
        helper(nums,mid+1,en,ans);
    }
     
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int st=0,en=n-1;
        
        helper(nums,st,en,ans);
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends