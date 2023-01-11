class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return x;
        int st=1,en=x;
        int ans;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(mid<=x/mid)
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