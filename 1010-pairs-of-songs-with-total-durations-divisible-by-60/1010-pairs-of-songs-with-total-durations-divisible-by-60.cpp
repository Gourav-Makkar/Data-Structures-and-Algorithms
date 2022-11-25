class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>m;
        
        int n=time.size();
        int j=0;
        int ans=0;
        while(j<n)
        {
            int rem=time[j]%60;
            if(rem!=0 && m.find(60-rem)!=m.end())
            {
                ans+=m[60-rem];
            }
            else if(rem==0 && m.find(0)!=m.end())
            {
                ans+=m[0];
            }
            m[rem]++;
            j++;
        }
        return ans;
    }
};