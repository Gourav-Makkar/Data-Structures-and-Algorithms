class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        
        int n=num.size();
        string s=to_string(k);
        
        int i=n-1,j=s.size()-1;
        int carry=0;
        
        while(i>=0 || j>=0)
        {
            int temp=carry;
            
            if(i>=0)
                temp+=num[i--];
            if(j>=0)
                temp+=(s[j--]-'0');
            ans.push_back(temp%10);
            carry=temp/10;
        }
        if(carry>0)
            ans.push_back(carry);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};