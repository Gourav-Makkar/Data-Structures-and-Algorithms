class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        // int ans=INT_MAX;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        
        vector<vector<int>>ans(r,vector<int>(c,INT_MAX));
        ans[0][0]=0;
        
        while(!pq.empty())
        {
            int eff=pq.top().first;
            int cr=pq.top().second.first;
            int cc=pq.top().second.second;
            pq.pop();
            
            if(cr>0)
            {
                int cf=max(eff,abs(heights[cr][cc]-heights[cr-1][cc]));
                if(cf<ans[cr-1][cc])
                {
                    pq.push({cf,{cr-1,cc}});
                    ans[cr-1][cc]=cf;
                }
            }
            if(cc<c-1)
            {
                int cf=max(eff,abs(heights[cr][cc]-heights[cr][cc+1]));
                if(cf<ans[cr][cc+1])
                {
                    pq.push({cf,{cr,cc+1}});
                    ans[cr][cc+1]=cf;
                }
            }
            if(cr<r-1)
            {
                int cf=max(eff,abs(heights[cr][cc]-heights[cr+1][cc]));
                if(cf<ans[cr+1][cc])
                {
                    pq.push({cf,{cr+1,cc}});
                    ans[cr+1][cc]=cf;
                }
            }
            if(cc>0)
            {
                int cf=max(eff,abs(heights[cr][cc]-heights[cr][cc-1]));
                if(cf<ans[cr][cc-1])
                {
                    pq.push({cf,{cr,cc-1}});
                    ans[cr][cc-1]=cf;
                }
            }
        }
        return ans[r-1][c-1];
    }
};