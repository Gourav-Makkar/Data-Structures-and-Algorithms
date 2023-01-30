class Solution {
public:
    int tribonacci(int n) {
       if(n==0)
           return 0;
        if(n==1 || n==2)
            return 1;
        int f=0,s=1,t=1;
        int ans;
        
        for(int i=0;i<=n-3;i++)
        {
            ans=f+s+t;
            f=s;
            s=t;
            t=ans;
        }
        return ans;
    }
};