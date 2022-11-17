class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>st(k+1),en(k+1);
        
        st[0]=0;
        for(int i=1;i<=k;i++)
        {
            st[i]=st[i-1]+cardPoints[i-1];
        }
        
        en[0]=0;
        for(int i=1;i<=k;i++)
        {
            en[i]=en[i-1]+cardPoints[n-i];
        }
        int ans=INT_MIN;
        for(int i=0;i<=k;i++)
        {
            int cs=st[i]+en[k-i];
            ans=max(ans,cs);
        }
        return ans;
    }
};