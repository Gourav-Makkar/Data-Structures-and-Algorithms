class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
       int ctOnes=0,flips=0;
        
       for(auto it:s)
       {
           if(it=='0')
               flips++;
           if(it=='1')
               ctOnes++;
           
           flips=min(flips,ctOnes);
       }
        return flips;
    }
};