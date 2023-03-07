class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)
            return 1;
        int idx=n-2;
        int diff=4+4*idx;
        
        long long ans=0;
        while(diff!=0)
        {
            ans+=diff;
            diff-=4;
        }
        ans++;
        return ans;
    }
};