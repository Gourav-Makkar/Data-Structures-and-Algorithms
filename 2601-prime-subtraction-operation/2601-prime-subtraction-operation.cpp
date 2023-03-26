class Solution {
public:
    
    bool checkPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    
    int findPrime(int n)
    {
        while(n>1)
        {
            if(checkPrime(n))
                return n;
            n--;
        }
        return -1;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        
        for(int i=0;i<n;i++)
        {
            int val=findPrime(nums[i]-prev-1);
            if(val==-1)
            {
                if(nums[i]>prev)
                  prev=nums[i];
                else
                    return false;
            }
            else
              prev=nums[i]-val;
        }
        return true;
    }
};