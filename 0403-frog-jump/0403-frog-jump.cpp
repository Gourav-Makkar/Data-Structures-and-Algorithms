#define ll long long
class Solution {
public:
    
    bool helper(int curr,unordered_set<int>&s,int prev,int des,map<pair<ll,ll>,ll>&dp)
    {
        if(curr<0 || curr>des || s.find(curr)==s.end())
            return false;
        
        if(curr==des)
            return true;
        
        if(dp.find({curr,prev})!=dp.end())
            return dp[{curr,prev}];
        
        int first=helper(curr+prev,s,prev,des,dp);
        int second=helper(curr+prev+1,s,prev+1,des,dp);
        int third=false;
        if(prev!=1)
            third=helper(curr+prev-1,s,prev-1,des,dp);
        
        return dp[{curr,prev}]=first||second||third;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
            return false;
        
        unordered_set<int>s;
        ll val=INT_MIN;
        for(auto it:stones)
        {
            s.insert(it);
            val=max(val,(long long)it);
        }
        
        map<pair<ll,ll>,ll>dp;
        
        return helper(1,s,1,stones[stones.size()-1],dp);
    }
};