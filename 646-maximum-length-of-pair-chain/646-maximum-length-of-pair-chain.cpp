class Solution {
public:
    // int ans=0;
    // void helper(vector<vector<int>>pairs,int prev,int curr)
    // {
    //     ans=max(ans,curr);
    //     for(int i=0;i<pairs.size();i++)
    //     {
    //         if(prev<pairs[i][0])
    //         {
    //             int newPrev=pairs[i][1];
    //             vector<vector<int>>newPairs=pairs;
    //             newPairs.erase(newPairs.begin()+i);
    //             helper(newPairs,newPrev,curr+1);
    //         }
    //     }
    // }
     static bool cmp(vector <int> &a, vector <int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        //helper(pairs,INT_MIN,0);
        int n=pairs.size();
        int ans=1;
        sort(pairs.begin(),pairs.end(),cmp);
        int curr,prev;
        for(int i=0;i<n;i++)
        {
            curr=1;
            prev=pairs[i][1];
            for(int j=i+1;j<n;j++)
            {
                if(prev<pairs[j][0])
                {
                    curr++;
                    prev=pairs[j][1];
                }
            }
            ans=max(ans,curr);
        }
         return ans;   
    }
};