class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int cto1=0,ctz1=0,cto2=0,ctz2=0;
        
        for(auto it:s)
        {
            if(it=='0')
                ctz1++;
            else
                cto1++;
        }
        
        for(auto it:target)
        {
            if(it=='0')
                ctz2++;
            else
                cto2++;
        }
        
        if(cto1!=0 && cto2!=0)
            return true;
        
        else if(cto1==0 && cto2==0 || ctz1==0 && ctz2==0)
            return s==target;
        
        return false;
    }
};