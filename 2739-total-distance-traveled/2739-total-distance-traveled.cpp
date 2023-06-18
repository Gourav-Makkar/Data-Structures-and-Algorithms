class Solution {
public:
    int distanceTraveled(int mt, int at) {
       
        int ct=0,temp=mt;
        while(temp>=5 && at>0)
        {
            temp-=5;
            temp++;
            ct++;
            at--;
        }
        
        return (mt+ct)*10;
    }
};