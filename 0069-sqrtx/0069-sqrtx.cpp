class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0)
            return x;
        int st=0,en=x/2;
        int ans;
        
        while(st<=en)
        {
            long long mid=st+(en-st)/2;
            
            if(mid*mid<=x)
            {
                ans=mid;
                st=mid+1;
            }
            else
                en=mid-1;
        }
        return ans;
    }
};