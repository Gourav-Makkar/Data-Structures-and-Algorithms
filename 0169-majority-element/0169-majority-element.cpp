class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=-1;
        int ct=0;
        
        for(auto it:nums)
        {
            if(ct==0)
            {
                candidate=it;
                ct++;
            }
            else if(it==candidate)
                ct++;
            else
                ct--;
        }
        return candidate;
    }
};