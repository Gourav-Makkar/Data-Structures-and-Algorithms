class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int teams=n/2;
        
        long long sum=0;
        for(int i=0;i<n;i++)
            sum+=skill[i];
        if(sum%teams!=0)
            return -1;
        
        sort(skill.begin(),skill.end());
        
        int i=0,j=n-1;
        long long prev=skill[i]+skill[j];
        long long ch=0;
        while(i<j)
        {
            int sc=skill[i]+skill[j];
            if(sc!=prev)
                return -1;
            ch+=(skill[i]*skill[j]);
            i++;
            j--;
        }
        return ch;
    }
};