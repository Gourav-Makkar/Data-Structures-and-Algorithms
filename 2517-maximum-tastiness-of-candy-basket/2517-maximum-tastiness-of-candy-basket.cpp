class Solution {
public:
    
    bool check(vector<int>&prices,int mid,int k)
    {
        int last=prices[0];
        int ct=1;
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-last>=mid)
            {
                ct++;
                last=prices[i];
            }
        }
        return ct>=k;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        if(n==1)
            return price[0];
        
        sort(price.begin(),price.end());
        
        int st=0;
        int en=price[n-1]-price[0];
        
        int ans=0;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(price,mid,k))
            {
                ans=mid;
                st=mid+1;
            }
            else
                en=mid-1;
        }
        return ans;
    }
};