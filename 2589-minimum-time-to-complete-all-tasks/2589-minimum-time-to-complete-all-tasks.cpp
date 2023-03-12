class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]!=b[1])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        
        unordered_map<int,bool>running;
        int total=0;
        
        for(auto it:tasks)
        {
            int alreadyOn=0;
            for(int t=it[0];t<=it[1];t++)
            {
                if(running[t])
                    alreadyOn++;
            }
            
            for(int t=it[1];it[2]>alreadyOn;t--)
            {
                if(!running[t])
                {
                    total++;
                    alreadyOn++;
                    running[t]=1;
                }
            }
        }
        return total;
    }
};