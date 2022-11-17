class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        int l=n-k;
        
        for(int i=0;i<n;i++)
            sum+=cardPoints[i];
        
        int i=0,j=0;
        int ans=INT_MAX;
        int cs=0;
        while(j<n)
        {
            cs+=cardPoints[j];
            if(j-i+1==l)
                ans=min(ans,cs);
            else if(j-i+1>l)
            {
                while(j-i+1>l)
                {
                    cs-=cardPoints[i];
                    i++;
                }
                ans=min(ans,cs);
            }
            j++;
        }
        return sum-ans;
            
    }
};