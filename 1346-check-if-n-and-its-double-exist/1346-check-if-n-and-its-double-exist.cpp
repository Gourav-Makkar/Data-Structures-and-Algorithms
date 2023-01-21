class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>s;
        
        for(auto it:arr)
        {
            if(s.find(2*it)!=s.end() || it%2==0 && s.find(it/2)!=s.end())
                return true;
            s.insert(it);
        }
        return false;
    }
};