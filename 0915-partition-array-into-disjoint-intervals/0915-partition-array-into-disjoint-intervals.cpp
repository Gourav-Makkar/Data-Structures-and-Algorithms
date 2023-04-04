class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        map<int,int>m;
        
        for(auto it:nums)
            m[it]++;
        
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
            m[nums[i]]--;
            
            if(m[nums[i]]==0)
                m.erase(nums[i]);
            
            auto it=m.begin();
            
            if(it->first>=mx)
                return i+1;
            
        }
        return n;
    }
};