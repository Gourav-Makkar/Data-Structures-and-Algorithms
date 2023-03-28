class Solution {
public:
    
    bool check(int mid,vector<int>&v,int days)
    {
        int ct=1,curr=0;
        
        for(int i=0;i<v.size();i++)
        {
            if(curr+v[i]<=mid)
                curr+=v[i];
            else
            {
                curr=v[i];
                ct++;
            }
        }
        return ct<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
       int st=INT_MIN,en=0;
        
       for(auto it:weights)
       {
           st=max(st,it);
           en+=it;
       }
        
       int ans;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            if(check(mid,weights,days))
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