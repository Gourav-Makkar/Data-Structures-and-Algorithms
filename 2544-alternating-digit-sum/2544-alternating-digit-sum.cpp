class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>digits;
        while(n>0)
        {
            int rem=n%10;
            digits.push_back(rem);
            n=n/10;
        }
        reverse(digits.begin(),digits.end());
        int ans=0;
        bool flag=true;
        for(auto it:digits)
        {
            if(flag)
                ans+=it;
            else
                ans-=it;
            flag=!flag;
        }
        return ans;
    }
};