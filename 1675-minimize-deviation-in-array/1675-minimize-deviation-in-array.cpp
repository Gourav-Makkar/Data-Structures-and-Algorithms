class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(auto it:nums)
        {
            if(it%2!=0)
                s.insert(2*it);
            else
                s.insert(it);
        }
    
        int ans=*s.rbegin()-*s.begin();
        while(*s.rbegin() % 2==0)
        {
            int ele=*s.rbegin();
            s.erase(ele);
            s.insert(ele/2);
            
            ans=min(ans,*s.rbegin()-*s.begin());
        }
        return ans;
    }
};