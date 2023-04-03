class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
        int n=people.size();
        int i=0,j=n-1,ans=0;
        
        while(i<=j)
        {
            if(i==j)
            {
                ans++;
                break;
            }
            if(people[i]+people[j]<=limit)
                i++;
            ans++;
            j--;
        }
        return ans;
    }
};