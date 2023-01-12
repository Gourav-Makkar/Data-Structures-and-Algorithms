class Solution {
public:
    
    static bool cmp(string &a,string &b)
    {
        string s1=a+b;
        string s2=b+a;
        
        return s1>s2;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans="";
        
        vector<string>v;
        for(auto it:nums)
            v.push_back(to_string(it));
        sort(v.begin(),v.end(),cmp);
        
        for(auto it:v)
            ans+=it;
        
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};