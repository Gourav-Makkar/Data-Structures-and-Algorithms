class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int n=x;
        long long temp=0;
        while(n>0)
        {
            int rem=n%10;
            temp=temp*10+rem;
            n=n/10;
        }
        if(temp==x)
            return true;
        return false;
    }
};