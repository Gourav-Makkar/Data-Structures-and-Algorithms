class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        
        map<int,int>m;
        int i=0,j=0,n=nums.size();
        
        while(j<n)
        {
            m[nums[j]]++;
            
            if(j-i+1==k)
            {
                auto it=m.rbegin();
                int val=it->first;
                ans.push_back(val);
                
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};