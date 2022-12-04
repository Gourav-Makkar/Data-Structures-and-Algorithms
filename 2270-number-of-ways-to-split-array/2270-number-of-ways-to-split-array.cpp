#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        ll sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        ll ls=0;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            ls+=nums[i];
            ll rs=sum-ls;
            
            if(ls>=rs)
                ans++;
        }
        return ans;   
    }
};