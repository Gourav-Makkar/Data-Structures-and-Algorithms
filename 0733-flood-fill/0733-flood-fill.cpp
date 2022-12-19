class Solution {
public:
    
    void dfs(vector<vector<int>>&image,int cr,int cc,int init,int color,vector<vector<int>>&ans)
    {
        if(cr<0 || cc<0 || cr==image.size() || cc==image[0].size() || image[cr][cc]!=init || image[cr][cc]==-1)
            return;
        
        ans[cr][cc]=color;
        image[cr][cc]=-1;
        
        dfs(image,cr-1,cc,init,color,ans);
        dfs(image,cr,cc+1,init,color,ans);
        dfs(image,cr+1,cc,init,color,ans);
        dfs(image,cr,cc-1,init,color,ans);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int init=image[sr][sc];
        
        dfs(image,sr,sc,init,color,ans);
        return ans;
    }
};