//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool cmp(pair<double,double>&a,pair<double,double>&b)
    {
        return a.first*b.second > b.first*a.second;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<double,double>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i].value,arr[i].weight});
        }
        sort(v.begin(),v.end(),cmp);
        
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i].second<=w)
            {
                ans+=v[i].first;
                w-=v[i].second;
            }
            else
            {
                ans+=((w/v[i].second)*v[i].first);
                break;
            }
            if(w==0)
              break;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends