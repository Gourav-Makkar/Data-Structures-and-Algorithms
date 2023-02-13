class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<long long,vector<int>>m;
        vector<vector<int>>ans;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            
            if(s[i]=='0')
            {
                if(m.count(0)==0)
                    m[0]={i,i};
                continue;
            }
            
            long long curr=0;
            for(int j=i;j<=min(i+31,n-1);j++)
            {
                curr=(curr<<1);
                curr+=(s[j]-'0');
                
                if(m.count(curr)==0)
                    m[curr]={i,j};
            }
        }
        
        for(int i=0;i<queries.size();i++)
        {
            long long target=queries[i][0]^queries[i][1];
            
            if(m.find(target)==m.end())
                ans.push_back({-1,-1});
            else
                ans.push_back(m[target]);
        }
        return ans;
    }
};