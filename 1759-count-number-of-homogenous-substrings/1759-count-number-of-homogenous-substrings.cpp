class Solution {
public:
    int countHomogenous(string s) {
        unordered_map<char,int>m;
        int n=s.size();
        
        int i=0,j=0;
        long long ans=0;
        
        while(j<n)
        {
            m[s[j]]++;
            while(m.size()>1)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
            
            if(m.size()==1)
            {
                cout<<j-i+1<<endl;
                ans+=(j-i+1);
                ans=ans%1000000007;
            }
            j++;
        }
        return ans;
    }
};