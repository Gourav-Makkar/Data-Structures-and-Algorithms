class Solution {
public:
    int countOdds(int low, int high) {
        bool st=false,en=false;
        
        if(low%2!=0)
            st=true;
        
        if(high%2!=0)
            en=true;
        
        int ct=(high-low)/2;
        
        if(st || en)
            ct++;
        return ct;
    }
};