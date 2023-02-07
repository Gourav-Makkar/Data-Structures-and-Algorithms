class Solution {
public:
    bool judgeSquareSum(int c) {
      if(c<=2)
          return true;
        
      long long mx=sqrt(c);
        
      for(int i=1;i<=mx;i++)
      {
          long long val=c-i*i;
          int a=sqrt(val);
          
          if(a*a==val)
              return true;
      }
        return false;
    }
};