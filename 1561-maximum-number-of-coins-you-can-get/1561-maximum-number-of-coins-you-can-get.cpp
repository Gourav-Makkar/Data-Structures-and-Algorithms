class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int st=0,en=n-1;
        
        int ans=0;
        sort(piles.begin(),piles.end());
        while(st<en)
        {
            ans+=piles[en-1];
            en=en-2;
            st++;
        }
        return ans;
    }
};