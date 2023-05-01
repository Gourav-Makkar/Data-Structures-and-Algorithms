class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0,mx=INT_MIN,mn=INT_MAX,n=salary.size();
        
        for(auto it:salary)
        {
            sum+=it;
            mx=max(mx,(double)it);
            mn=min(mn,(double)it);
        }
        
        sum-=(mx+mn);
        return sum/(n-2);
    }
};