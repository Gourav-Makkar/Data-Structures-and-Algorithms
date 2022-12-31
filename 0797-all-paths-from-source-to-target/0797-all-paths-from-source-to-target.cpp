class Solution {
public:
    
    void helper(vector<vector<int>>&graph,int curr,int des,vector<int>&vis,vector<vector<int>>&ans,vector<int>temp)
    {
        if(vis[curr]==1)
            return;
        if(curr==des)
        {
            temp.push_back(curr);
            ans.push_back(temp);
            return;
        }
        
        vis[curr]=1;
        temp.push_back(curr);
        
        for(auto it:graph[curr])
        {
            helper(graph,it,des,vis,ans,temp);
        }
        
        vis[curr]=0;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
        vector<int>vis(n,0);
        
        helper(graph,0,n-1,vis,ans,{});
        
        return ans;
    }
};