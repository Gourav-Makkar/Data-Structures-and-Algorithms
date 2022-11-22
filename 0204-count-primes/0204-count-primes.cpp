class Solution {
public:
    
    // bool isPrime(int n)
    // {
    //     if(n==2 || n==3)
    //         return true;
    //     if(n%2==0 || n%3==0)
    //         return false;
    //     for(int i=5;i*i<=n;i++)
    //     {
    //          if(n%i==0)
    //             return false;
    //     }
    //     return true;
    // }
    
    int countPrimes(int n) {
        int ct=0;
        vector<bool>isPrime(n,true);
        
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i])
            {
                for(int j=2*i;j<n;j=j+i)
                    isPrime[j]=false;
            }
        }
        for(int i=2;i<n;i++)
        {
            if(isPrime[i])
                ct++;
        }
        return ct;
    }
};