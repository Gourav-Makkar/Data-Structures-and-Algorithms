class Solution {
public:
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int>ans(m);
        
        for(int i=0;i<m;i++)
        {
            int sum=queries[i];
            int cs=0,cl=0;
            
            for(int j=0;j<n;j++)
            {
                if(cs+nums[j]>sum)
                    break;
                cs+=nums[j];
                cl++;
            }
            ans[i]=cl;
        }
        
        return ans;
    }
};