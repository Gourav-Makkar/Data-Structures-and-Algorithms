class Solution {
public:
    bool isBipartite(int node,int color,vector<int>& isVisited,vector<int> adj[]){
        isVisited[node]=color;
        int adjColor=(color==1)?2:1;
        for(auto i:adj[node]){
            if(!isVisited[i]){
                if(isBipartite(i,adjColor,isVisited,adj)){
                    return true;
                }
            }
            else if(isVisited[i]==color){
                return true;
            }
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto i:dislikes){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> isVisited(n+1,0);
        for(int i=1;i<=n;i++){
            if(!isVisited[i]){
                if(isBipartite(i,1,isVisited,adj)) return false;
            }
        }
        return true;
    }
};