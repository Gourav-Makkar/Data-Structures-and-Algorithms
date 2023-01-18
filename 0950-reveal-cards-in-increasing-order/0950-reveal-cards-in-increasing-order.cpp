class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int>ans(n,-1);
        bool flag=true;
        
        int i=0,j=0;
        
        while(j<n)
        {
            if(ans[i]==-1)
            {
                if(flag)
                {
                    ans[i]=deck[j];
                    j++;  
                }
                flag=!flag;
            }
            i=(i+1)%n;
            
        }
        return ans;
    }
};