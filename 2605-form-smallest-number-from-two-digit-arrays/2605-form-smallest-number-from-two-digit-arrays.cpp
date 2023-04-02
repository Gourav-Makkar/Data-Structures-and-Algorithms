class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mn1=INT_MAX,mn2=INT_MAX,c=INT_MAX;
        unordered_set<int>s;
        
        
        for(auto it:nums1)
        {
            mn1=min(mn1,it);
            s.insert(it);
        }
        
        for(auto it:nums2)
        {
            mn2=min(mn2,it);
            if(s.find(it)!=s.end())
                c=min(c,it);
        }
        
        string temp=to_string(mn1)+to_string(mn2);
        sort(temp.begin(),temp.end());
        
        return min(c,stoi(temp));
        
    }
};