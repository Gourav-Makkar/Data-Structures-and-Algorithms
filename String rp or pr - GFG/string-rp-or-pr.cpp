//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int x,int y,string s){
       long long ans=0;
       int n=s.size();
       stack<char>st;
       bool flag=false;
       
       if(y>x)
         flag=true;
       
       for(int i=0;i<n;i++)
       {
           if(st.empty())
           {
               st.push(s[i]);
               continue;
           }
           char ch=st.top();
           
           if(ch=='p' && s[i]=='r')
           {
               if(flag)
               {
                   st.push(s[i]);
                   continue;
               }
               ans+=x;
               st.pop();
           }
           else if(ch=='r' && s[i]=='p')
           {
               if(flag)
               {
                   ans+=y;
                   st.pop();
               }
               else
                  st.push(s[i]);
           }
           else
             st.push(s[i]);
       }
       
       if(flag)
       {
           string temp="";
           while(!st.empty())
           {
               temp+=st.top();
               st.pop();
           }
           reverse(temp.begin(),temp.end());
           
           for(int i=0;i<temp.size();i++)
           {
               if(st.empty())
               {
                   st.push(temp[i]);
                   continue;
               }
               char ch=st.top();
               
               if(ch=='p' && temp[i]=='r')
               {
                   ans+=x;
                   st.pop();
               }
               else
                 st.push(temp[i]);
           }
       }
       else
       {
           string temp="";
           while(!st.empty())
           {
               temp+=st.top();
               st.pop();
           }
           reverse(temp.begin(),temp.end());
           
           for(int i=0;i<temp.size();i++)
           {
               if(st.empty())
               {
                   st.push(temp[i]);
                   continue;
               }
               char ch=st.top();
               
               if(ch=='r' && temp[i]=='p')
               {
                   ans+=y;
                   st.pop();
               }
               else
                 st.push(temp[i]);
           }
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends