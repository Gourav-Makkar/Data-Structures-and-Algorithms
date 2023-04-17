class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        int mx=INT_MIN;
        
        for(auto it:candies)
            mx=max(it,mx);
        
        vector<bool>ans(n,false);
        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=mx)
                ans[i]=true;
        }
        return ans;
    }
};