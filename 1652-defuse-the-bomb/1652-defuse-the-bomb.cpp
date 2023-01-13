class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n);
        
        if(k==0)
            return ans;
        if(k>0)
        {
            for(int i=0;i<n;i++)
            {
                int ct=k;
                int j=(i+1)%n;
                while(ct--)
                {
                    ans[i]+=code[j];
                    j=(j+1)%n;
                }
            }
        }
        if(k<0)
        {
            for(int i=0;i<n;i++)
            {
                int ct=-k;
                int j=(i-1+n)%n;
                while(ct--)
                {
                    ans[i]+=code[j];
                    j=(j-1+n)%n;
                }
            }
        }
        return ans;
    }
};