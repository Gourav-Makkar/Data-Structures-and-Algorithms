class Solution {
public:
    string countAndSay(int n) {
       if(n==0)
           return "";
       string res="1";
       while(--n)
       {
           string curr="";
           for(int i=0;i<res.length();i++)
           {
               int ct=1;
               while(i+1<res.length() && res[i+1]==res[i])
               {
                   ct++;
                   i++;
               }
               curr+=to_string(ct)+res[i];
           }
           res=curr;
       }
        return res;
    }
};