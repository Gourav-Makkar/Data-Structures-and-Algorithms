class Solution {
public:
    int splitNum(int num) {
        string t=to_string(num);
        sort(t.begin(),t.end());
        
        string n1,n2;
        
        int i=0;
        bool flag=true;
        
        while(i<t.size())
        {
            if(flag)
                n1+=t[i];
            else
                n2+=t[i];
            i++;
            flag=!flag;
        }
        return stoi(n1)+stoi(n2);
    }
};