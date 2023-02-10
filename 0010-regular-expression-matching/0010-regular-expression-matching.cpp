class Solution {
public:
    
    bool helper(int idx1,int idx2,string &s,string &p)
    {
        if(idx1==0 && idx2==0)
            return true;
        
        if(idx2==0)
            return false;
        
        if(idx1==0)
          return (p[idx2-1]=='*' && helper(idx1,idx2-2,s,p));
        
        if(s[idx1-1]==p[idx2-1] || p[idx2-1]=='.')
            return helper(idx1-1,idx2-1,s,p);
        
        if(p[idx2-1]=='*')
        {
           bool first=helper(idx1,idx2-2,s,p);
           bool second=false;
           if(p[idx2-2]==s[idx1-1] || p[idx2-2]=='.')
               second=helper(idx1-1,idx2,s,p);
            
           return first||second;
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        
        return helper(n1,n2,s,p);
    }
};