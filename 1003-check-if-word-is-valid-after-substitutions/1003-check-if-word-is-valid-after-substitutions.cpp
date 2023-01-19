class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(auto it:s)
        {
            if(it=='c')
            {
                if(st.size()==0 || st.top()!='b')
                    return false;
                st.pop();
                if(st.size()==0 ||st.top()!='a')
                    return false;
                st.pop();
            }
            else
                st.push(it);
        }
        return st.size()==0;
    }
};