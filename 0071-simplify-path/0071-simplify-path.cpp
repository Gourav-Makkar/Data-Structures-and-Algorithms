class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n=path.size();
        
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
                continue;
            
            else
            {
                string temp="";
                while(i<n && path[i]!='/')
                {
                    temp+=path[i];
                    i++;
                }
                
                if(temp==".")
                    continue;
                
                else if(temp=="..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else
                    st.push(temp);
            }
        }
        string ans;
        
        while(!st.empty())
        {
            string temp=st.top();
            ans=temp+ans;
            ans="/"+ans;
            
            st.pop();
        }
       if(ans.size()==0)
           ans+="/";
        
       return ans;
    }
};