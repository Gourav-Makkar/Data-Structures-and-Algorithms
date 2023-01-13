class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int ans=0;
        int j=0;
        string curr="";
        while(j<s.length())
        {
            curr+=s[j];
            if(curr.size()==k)
            {
                int x=stoi(curr);
                if(x!=0 && num%x==0)
                    ans++;
                curr.erase(curr.begin());
            }
            j++;
        }
        return ans;
    }
};