class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        for(int i=0;i<a.size();i++)
        {
            if(st.empty())
                st.push(a[i]);
            
            else if(st.top()>0 && a[i]<0)
            {
                bool flag=false;
                int val=abs(a[i]);
                while(!st.empty())
                {
                    if(st.top()<0)
                   {
                        flag=true;
                        break;
                    }
                   if(val<st.top())
                     break;
                  else if(val==st.top())
                  {
                      st.pop();
                      break;
                  }
                    else
                    {
                        st.pop();
                        if(st.empty())
                        {
                            flag=true;
                            break;
                        }
                    }
                }
                
                if(flag)
                    st.push(a[i]);
            }
            else
                st.push(a[i]);
          }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};