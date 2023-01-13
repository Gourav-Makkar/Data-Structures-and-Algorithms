class Solution {
public:
    bool judgeSquareSum(int c) {
       int n=sqrt(c);  //possible value b can take
        
       for(int b=0;b<=n;b++)
       {
           int a= c - b*b;
           
           int temp=sqrt(a);
           if(temp*temp==a)
               return true;
       }
        return false;
    }
};