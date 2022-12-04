class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        long long ls=0;
        long long mn=INT_MAX;
        int mnIdx;
        
        for(int i=0;i<n;i++)
        {
            ls+=nums[i];
            long long rs=sum-ls;
            long long lAvg=ls/(i+1);
            long long rAvg=0;
            if(i!=n-1)
              rAvg=rs/(n-i-1);
            
            long long absDif=abs(lAvg-rAvg);
            
            if(absDif<mn)
            {
                mn=absDif;
                mnIdx=i;
            }
        }
        return mnIdx;
    }
};