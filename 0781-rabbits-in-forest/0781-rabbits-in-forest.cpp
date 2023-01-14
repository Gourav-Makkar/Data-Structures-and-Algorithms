class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int n=answers.size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(m.find(answers[i])==m.end())
            {
                ans+=answers[i]+1;
                m[answers[i]]++;
            }
            else
            {
                int ct=m[answers[i]];
                if(ct-answers[i]==1)
                {
                   ans+=answers[i]+1;
                   m[answers[i]]=1;
                }
                else
                    m[answers[i]]++;
            }
        }
        return ans;
    }
};