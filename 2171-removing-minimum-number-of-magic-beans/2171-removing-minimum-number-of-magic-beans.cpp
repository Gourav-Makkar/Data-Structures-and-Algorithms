class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long ans= 9223372036854775807;
        long long sum=0;
        int n=beans.size();
        for(int i=0;i<n;i++)
            sum+=beans[i];
        
        long long ls=0,rs=sum;
        
        for(int i=0;i<n;i++)
        {
            rs=rs-beans[i];
            ans=min(ans, ls + rs - (long long)(n-i-1)*(long long)(beans[i]));
            ls+=beans[i];
        }
        return ans;
    }
};