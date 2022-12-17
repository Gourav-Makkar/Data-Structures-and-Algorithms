class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int n=tokens.size();
        
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                long long f=stoll(st.top());
                st.pop();
                
                long long s=stoll(st.top());
                st.pop();
                
                if(tokens[i]=="+")
                {
                    long long res=s+f;
                    st.push(to_string(res));
                }
                if(tokens[i]=="-")
                {
                    long long res=s-f;
                    st.push(to_string(res));
                }
                if(tokens[i]=="*")
                {
                    long long res=s*f;
                    st.push(to_string(res));
                }
                if(tokens[i]=="/")
                {
                    long long res=s/f;
                    st.push(to_string(res));
                }
            }
            
            else
                st.push(tokens[i]);
        }
        return stoi(st.top()); 
    }
};