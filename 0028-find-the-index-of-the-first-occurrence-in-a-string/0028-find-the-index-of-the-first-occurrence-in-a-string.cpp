class Solution {
public:
    int strStr(string hay, string needle) {
        int n1=hay.length();
        int n2=needle.length();
        
        if(n2>n1)
            return -1;
        
        int i=0,j=0;
        list<char>l;
        
        
        while(j<n1)
        {
            l.push_back(hay[j]);
            
            if(l.size()==n2)
            {
                string temp(l.begin(),l.end());
                if(temp==needle)
                    return i;
                l.pop_front();
                i++;
            }
            j++;
        }
        return -1;
    }
};