class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0,n=tasks.size();
        unordered_map<int,int>m;
        
        for(auto it:tasks)
            m[it]++;
        
        for(int i=0;i<n;i++)
        {
            if(m.find(tasks[i])!=m.end())
            {
                if(m[tasks[i]]==1)
                    return -1;
                else if(m[tasks[i]]>4 || m[tasks[i]]==3)
                {
                    ans++;
                    m[tasks[i]]-=3;
                    if(m[tasks[i]]==0)
                        m.erase(tasks[i]);
                }
                else
                {
                    ans++;
                    m[tasks[i]]-=2;
                    if(m[tasks[i]]==0)
                        m.erase(tasks[i]);
                }
            }
        }
        return ans;
    }
};