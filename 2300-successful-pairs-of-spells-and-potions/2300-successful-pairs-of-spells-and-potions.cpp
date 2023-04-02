class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int n=potions.size();
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<spells.size();i++)
        {
            long long val=spells[i];
            long long temp;
            if(success%val==0)
                temp=success/val;
            else
                temp=ceil(success/(double)val);
            
            int idx=lower_bound(potions.begin(),potions.end(),temp)-potions.begin();
            ans.push_back(n-idx);
        }
        return ans;
    }
};