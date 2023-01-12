class Solution {
public:
    
    vector<int> helper(int curr,int parent,vector<int>adj[],string &labels,vector<int>&ans)
    {
        vector<int>freq(26,0);
        for(auto child:adj[curr])
        {
            if(child!=parent)
            {
                vector<int>childCt=helper(child,curr,adj,labels,ans);
                
                for(int i=0;i<26;i++)
                {
                    freq[i]+=childCt[i];
                }
            }
        }
        freq[labels[curr]-'a']++;
        ans[curr]=freq[labels[curr]-'a'];
        
        return freq;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>adj[n];
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>ans(n);
        
        helper(0,-1,adj,labels,ans);
        return ans;
    }
};