class Solution {
public:
    
    int helper(int idx,vector<vector<int>>&piles,int k,vector<vector<int>>&dp)
    {
        if(k==0)
            return 0;
        
        if(idx<0 || k<0)
            return INT_MIN;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        int take=0,cs=0;
        for(int i=0;i<piles[idx].size();i++)
        {
            cs+=piles[idx][i];
            int temp=cs+helper(idx-1,piles,k- (i+1),dp);
            take=max(take,temp);
        }
        
        int notTake=helper(idx-1,piles,k,dp);
        
        return dp[idx][k]=max(take,notTake);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         map<pair<int,int>,int>m;
//         int n=piles.size();
        
//         for(int i=0;i<n;i++)
//         {
//             int sum=0;
//             int ct=0;
            
//             for(auto it:piles[i])
//             {
//                 ct++;
//                 sum+=it;
                
//                 m[{i,ct}]=sum;
//             }
//         }
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        
        return helper(n-1,piles,k,dp);
    }
};