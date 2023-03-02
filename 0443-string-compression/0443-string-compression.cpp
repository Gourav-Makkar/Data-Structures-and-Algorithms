class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        string ans="";
        char prev=chars[0];
        int ct=1;
        
        int idx=1;
        while(idx<n)
        {
            char curr=chars[idx];
            if(curr==prev)
                ct++;
            
            else
            {
                ans+=prev;
                if(ct>1)
                    ans+=to_string(ct);
                ct=1;
                prev=curr;
            }
            idx++;
        }
        ans+=prev;
        if(ct>1)
            ans+=to_string(ct);
        chars.clear();
        for(auto it:ans)
            chars.push_back(it);
        
        return ans.size();
    }
};