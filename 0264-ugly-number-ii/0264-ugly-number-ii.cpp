class Solution {
public:
    
    int nthUglyNumber(int n) {
        set<long long>s;
        s.insert(1);
        
        auto it=s.begin();
        
        for(int i=0;i<n;i++)
        {
           long long val=*it;
           s.insert(2*val);
           s.insert(3*val);
           s.insert(5*val);
           
           it++;
        }
        int p=n-1;
        auto i=s.begin();
        advance(i,p);
        return int(*i);
    }
};