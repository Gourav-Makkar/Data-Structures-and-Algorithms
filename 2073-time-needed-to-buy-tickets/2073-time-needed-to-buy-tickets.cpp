class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) {
        int n=a.size();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i<=k)
                ans+=min(a[i],a[k]);
            else
                ans+=min(a[i],a[k]-1);
        }
        return ans;
    }
};