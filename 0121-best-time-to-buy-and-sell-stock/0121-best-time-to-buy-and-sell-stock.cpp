class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int curr=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<curr)
                curr=prices[i];
            else
                ans=max(ans,prices[i]-curr);
        }
        return ans;
    }
};