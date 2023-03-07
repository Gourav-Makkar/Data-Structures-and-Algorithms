class Solution {
public:
    
    bool check(long long mx,vector<int>&time,int trips)
    {
        long long ct=0;
        for(auto it:time)
            ct+=(mx/it);
        
        return ct>=trips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long st=1,en=INT_MIN,ans;
        
        for(auto it:time)
            en=max(en,(long long)it);
        
        en=en*totalTrips;
        
        while(st<=en)
        {
            long long mid=st+(en-st)/2;
            
            if(check(mid,time,totalTrips))
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