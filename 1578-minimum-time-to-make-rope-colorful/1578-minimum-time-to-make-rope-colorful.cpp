class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        for(int i=0;i<colors.length()-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                ans+=min(neededTime[i],neededTime[i+1]);
                neededTime[i+1]=max(neededTime[i],neededTime[i+1]);
            } 
        }
        return ans;
    }
};