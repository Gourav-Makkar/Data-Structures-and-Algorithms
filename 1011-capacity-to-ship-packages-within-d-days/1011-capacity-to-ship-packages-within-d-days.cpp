class Solution {
public:
    
    bool check(vector<int>&weights,int mxWeight,int days)
    {
        int ct=1;
        int cs=0;
        for(auto it:weights)
        {
            if(it>mxWeight)
                return false;
            cs+=it;
            if(cs>mxWeight)
            {
                ct++;
                cs=it;
            }
        }
        return ct<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int st=1,en=0;
        
        for(auto it:weights)
            en+=it;
        
        int ans;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(weights,mid,days))
            {
                ans=mid;
                en=mid-1;
            }
            else
                st=mid+1;
        }
        return ans;
    }
};