class Solution {
public:
    
    void helper(int idx,string &s,int target,string curr,long long prev,long long res,vector<string>&ans)
    {
        if(idx==s.size())
        {
            if(res==target)
                ans.push_back(curr);
            return;
        }
        
        string temp="";
        long long val=0;
        
        for(int i=idx;i<s.size();i++)
        {
            if(i>idx && s[idx] == '0')
                break;

            temp += s[i];
            val = val * 10 + (s[i] - '0');
            
            if(idx == 0)
                helper(i + 1, s , target  ,curr + temp , val , val,ans);

            else{
            helper(i + 1,s ,target , curr + "+" + temp , val , res + val,ans);
            helper(i + 1, s ,target , curr + "-" +  temp , -val , res - val, ans);
            helper(i + 1, s,target,curr + "*" + temp,prev*val ,res - prev +prev*val ,ans);
            }
         }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        
        helper(0,num,target,"",0,0,ans);
        return ans;
    }
};