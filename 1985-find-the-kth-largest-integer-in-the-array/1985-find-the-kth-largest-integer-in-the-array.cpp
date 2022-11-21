class compare {
public:
    
    bool operator()(string &a, string &b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return  a > b;
    }
};



class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        priority_queue<string,vector<string>,compare>p;
        
        for(int i=0;i<n;i++)
        {
            p.push(nums[i]);
            if(p.size()>k)
                p.pop();
        }
         return p.top();
        
    }
};