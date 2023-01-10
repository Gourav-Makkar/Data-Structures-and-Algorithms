class Solution {
public:
    
    void helper(string tiles,string &curr,unordered_set<string>&s,vector<int>&vis)
    {
        for(int i=0;i<tiles.size();i++)
        {
            if(vis[i]==0)
            {
                curr.push_back(tiles[i]);
                s.insert(curr);
                vis[i]=1;
                helper(tiles,curr,s,vis);
                
                vis[i]=0;
                curr.pop_back();
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_set<string>s;
        int n=tiles.size();
        vector<int>vis(n,0);
        string curr="";
        
        helper(tiles,curr,s,vis);
        return s.size();
    }
};