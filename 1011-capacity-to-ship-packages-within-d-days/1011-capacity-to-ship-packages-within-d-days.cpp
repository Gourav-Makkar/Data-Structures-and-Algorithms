class Solution {
public:
    
    bool check(vector<int>&weights,int mx,int days)
    {
        int cs=0,ct=1;
        for(auto it:weights)
        {
            if(cs+it<=mx)
              cs+=it;
            else
            {
                ct++;
                cs=it;
            }
        }
        return ct<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int ans;
        int st=INT_MIN,en=0;
        for(auto it:weights)
        {
            st=max(st,it);
            en+=it;
        }
        
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