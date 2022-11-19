class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        int sum=0;
        while(sum!=1)
        {
            sum=0;
            int t=n;
            while(t>0)
            {
                int rem=t%10;
                sum+=rem*rem;
                t=t/10;
            }
            if(s.find(sum)!=s.end())
                return false;
            s.insert(sum);
            n=sum;
        }
        return true;
    }
};