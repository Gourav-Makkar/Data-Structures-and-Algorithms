class Solution {
public:
    
    bool check(vector<int>&piles,int speed,int h)
    {
        long long ct=0;
        double s=speed;
        for(auto it:piles)
        {
            double val=it/s;
            ct+=ceil(val);
        }
        return ct<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1,en=INT_MIN;
        
        for(auto it:piles)
            en=max(it,en);
        
        int ans;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(piles,mid,h))
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