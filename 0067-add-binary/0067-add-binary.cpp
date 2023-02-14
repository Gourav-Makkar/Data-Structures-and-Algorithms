class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size();
        int n2=b.size();
        
        string ans="";
        
        int i=n1-1,j=n2-1;
        int carry=0;
        
        while(i>=0 || j>=0)
        {
            int val=carry;
            
            if(i>=0)
                val+=(a[i--]-'0');
            if(j>=0)
                val+=(b[j--]-'0');
            
            carry=(val>1)?1:0;
            ans+=to_string(val%2);
        }
        if(carry==1)
            ans+=to_string(carry);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};