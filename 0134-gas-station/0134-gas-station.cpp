class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        
        int cgas=0,tgas=0,tcost=0;
        int st=0;
        
        for(int i=0;i<n;i++)
        {
            tgas+=gas[i];
            tcost+=cost[i];
            
            cgas+=(gas[i]-cost[i]);
            if(cgas<0)
            {
                st=i+1;
                cgas=0;
            }
        }
        if(tgas<tcost)
            return -1;
        return st;
    }
};