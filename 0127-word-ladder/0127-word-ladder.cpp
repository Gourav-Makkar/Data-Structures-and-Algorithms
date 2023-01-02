class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& list) {
        int n=list.size();
        unordered_set<string>s;
        for(int i=0;i<n;i++)
            s.insert(list[i]);
        
        queue<pair<string,int>>q;
        q.push({beg,1});
        
        unordered_map<string,int>vis;
        for(auto it:list)
            vis[it]=0;
        
        vis[beg]=1;
        
        while(!q.empty())
        {
            string word=q.front().first;
            int dis=q.front().second;
            q.pop();
            
            if(word==end)
                return dis;
            
            for(int idx=0;idx<word.length();idx++)
            {
                string temp=word;
                for(int i=97;i<=122;i++)
                {
                    temp[idx]=i;
                    if(vis[temp]!=1 && s.find(temp)!=s.end())
                    {
                        vis[temp]=1;
                        q.push({temp,dis+1});
                    }
                }
            }
        }
        return 0;
    }
};