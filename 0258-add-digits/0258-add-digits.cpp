class Solution {
public:
    int addDigits(int num) {
        while(num>=10)
        {
            string temp=to_string(num);
            int sum=0;
            for(auto it:temp)
                sum+=(it-'0');
            num=sum;
        }
        return num;
    }
};