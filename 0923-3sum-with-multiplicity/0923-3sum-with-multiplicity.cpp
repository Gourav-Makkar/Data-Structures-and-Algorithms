class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {        
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int tar=target-arr[i];
            unordered_map<int,int>m;
            int k=i+1,cs=0;
            
            while(k<n)
            {
                if(m.find(tar-arr[k])!=m.end())
                {
                     ans+=m[tar-arr[k]];
                     ans=ans%1000000007;
                }
                m[arr[k]]++;
                k++;
            }
        }
        return ans;
    }
};