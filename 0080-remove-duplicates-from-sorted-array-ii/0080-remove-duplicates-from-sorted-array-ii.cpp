class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        unordered_map<int,int>m;
        m[nums[0]]++;
        
        for(int i=1;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]++;
                swap(nums[i],nums[k]);
                k++;
            }
            else
            {
                if(m[nums[i]]==1)
                {
                    m[nums[i]]++;
                    swap(nums[i],nums[k]);
                    k++;
                }
            }
        }
        return k;
    }
};