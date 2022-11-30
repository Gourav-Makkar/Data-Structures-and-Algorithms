class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
            m[arr[i]]++;
        unordered_set<int>occu;
        for(auto it:m)
            occu.insert(it.second);
        return (m.size()==occu.size());
    }
};