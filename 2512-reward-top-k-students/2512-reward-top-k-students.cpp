class Solution {
public:
    
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        
        return a.second>b.second;
    }
    
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& report, vector<int>& students, int k) {
        
        unordered_set<string>pos,neg;
        
        for(auto s:pf)
            pos.insert(s);
        for(auto s:nf)
            neg.insert(s);
        
        vector<pair<int,int>>ans;
        
        int n=students.size();
        
        for(int i=0;i<n;i++)
        {
            string word="";
            int score=0;
            for(int j=0;j<report[i].size();j++)
            {
                if(report[i][j]==' ')
                {
                    if(pos.find(word)!=pos.end())
                        score=score+3;
                    
                    if(neg.find(word)!=neg.end())
                        score=score-1;
                    
                    word="";
                }
                else
                    word+=report[i][j];
            }
            if(word!="")
            {
                if(pos.find(word)!=pos.end())
                        score=score+3;
                    
                if(neg.find(word)!=neg.end())
                    score=score-1;
            }
            ans.push_back({students[i],score});
           
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].first);
        }
        
        return res;
    }
};