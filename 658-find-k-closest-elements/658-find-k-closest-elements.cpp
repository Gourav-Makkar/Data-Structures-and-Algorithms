class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        if(k==n)
            return arr;
        vector<int>ans;
        vector<vector<int>>temp;
        for(int i=0;i<n;i++)
        {
            int dif=abs(x-arr[i]);
            temp.push_back({dif,arr[i]});
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<k;i++)
        {
            ans.push_back(temp[i][1]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};