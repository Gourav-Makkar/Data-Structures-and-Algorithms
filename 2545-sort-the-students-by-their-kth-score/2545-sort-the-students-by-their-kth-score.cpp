class Solution {
public:
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int r=score.size();
        int c=score[0].size();
        vector<vector<int>>ans;
        vector<pair<int,int>>temp;
        for(int i=0;i<r;i++)
        {
            temp.push_back({score[i][k],i});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        
        for(auto it:temp)
            ans.push_back(score[it.second]);
        return ans;
       
    }
};