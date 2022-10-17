class Solution {
public:
    
//     MEMOIZATION
    
//     int helper(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp)
//     {
//         if(j<0 || j>=matrix[0].size())
//             return 1e9;
//         if(i==matrix.size()-1)
//             return matrix[i][j];
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         int down=matrix[i][j]+helper(matrix,i+1,j,dp);
//         int diagLeft=matrix[i][j]+helper(matrix,i+1,j-1,dp);
//         int diagRight=matrix[i][j]+helper(matrix,i+1,j+1,dp);
        
//         return dp[i][j]=min(down,min(diagLeft,diagRight));
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int ans=INT_MAX;
        
        // vector<vector<int>>dp(r,vector<int>(c,-1));
        // for(int i=0;i<c;i++)
        // {
        //     ans=min(ans,helper(matrix,0,i,dp));
        // }
        // return ans;
//         for(int j=0;j<c;j++)
//         {
//             dp[r-1][j]=matrix[r-1][j];
//         }
//        for(int i=r-2;i>=0;i--)
//         {
//             for(int j=0;j<c;j++)
//             {
//                 int down=0,diagleft=1e9,diagright=1e9;
//                 down=matrix[i][j]+dp[i+1][j];
//                 if(j>0)
//                     diagleft=matrix[i][j]+dp[i+1][j-1];
//                 if(j<c-1)
//                     diagright=matrix[i][j]+dp[i+1][j+1];
                
//                 dp[i][j]=min(down,min(diagleft,diagright));
//             }
//         }
        
//         for(int i=0;i<c;i++)
//         {
//             ans=min(ans,dp[0][i]);
//         }
//         return ans;
        
//         SPACE OPTIMISED
        vector<int>prev(c,-1);
        for(int i=0;i<c;i++)
        {
            prev[i]=matrix[r-1][i];
        }
        
        for(int i=r-2;i>=0;i--){
            vector<int>curr(c,-1);
            for(int j=0;j<c;j++)
            {
                int down=0,diagleft=1e9,diagright=1e9;
                down=matrix[i][j]+prev[j];
                if(j>0)
                    diagleft=matrix[i][j]+prev[j-1];
                if(j<c-1)
                    diagright=matrix[i][j]+prev[j+1];
                
                curr[j]=min(down,min(diagleft,diagright));
            }
            prev=curr;
        }
        for(int i=0;i<c;i++)
        {
            ans=min(ans,prev[i]);
        }
        return ans;
    }
};