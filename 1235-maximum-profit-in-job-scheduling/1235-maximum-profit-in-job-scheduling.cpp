class Solution {
public:
   static bool cmp(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b)
   {
       return a.first<b.first;
   }
    int helper(vector<int>&st,vector<int>&en,vector<int>&profit,int idx,vector<int>&dp)
    {
        if(idx==st.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        int index = lower_bound(st.begin(),st.end(),en[idx]) - st.begin();
        int take=profit[idx]+helper(st,en,profit,index,dp);
        int notTake=0+helper(st,en,profit,idx+1,dp);
        
        return dp[idx]=max(take,notTake);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)     { 
        int n=profit.size();
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        
        sort(v.begin(),v.end(),cmp);
        startTime.clear();
        endTime.clear();
        profit.clear();
       
        for(int i=0;i<n;i++)
        {
            startTime.push_back(v[i].first);
            endTime.push_back(v[i].second.first);
            profit.push_back(v[i].second.second);
        }
        vector<int>dp(n,-1);
        return helper(startTime,endTime,profit,0,dp);
    }
};