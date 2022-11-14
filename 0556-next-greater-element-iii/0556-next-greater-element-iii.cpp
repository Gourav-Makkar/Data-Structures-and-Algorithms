class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>v;
        int t=n;
        while(n>0)
        {
            int rem=n%10;
            v.push_back(rem);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        int d=v.size();
        int idx=-1;
        int j=d-1,i=d-2;
        while(i>=0)
        {
            if(v[j]>v[i])
            {
                idx=i;
                break;
            }
            i--;
            j--;
        }
        if(idx==-1)
            return -1;
        for(int i=d-1;i>idx;i--)
        {
            if(v[i]>v[idx])
            {
                swap(v[i],v[idx]);
                break;
            }
        }
        reverse(v.begin()+i+1,v.end());
        
        long ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans=ans * 10 + v[i];
            if(ans > INT_MAX)
                return -1;
        }

        return ans;
    }
};