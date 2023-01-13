class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0,j=n-1,ans=0;
        
        
        while(i<=j)
        {
            if(i==j)
                break;
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
            }
            else
                j--;
            ans++;
        }
        if(i==j)
            ans++;
        return ans;
    }
};