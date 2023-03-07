class Solution {
public:
    
    int helper(int curr,int ct,int time,int n,int val)
    {
        if(ct==time)
            return curr;
        
        if(curr==1)
            val=1;
        
        if(curr==n)
            val=-1;
        
        return helper(curr+val,ct+1,time,n,val);
    }
    
    int passThePillow(int n, int time) {
        return helper(1,0,time,n,1);
    }
};