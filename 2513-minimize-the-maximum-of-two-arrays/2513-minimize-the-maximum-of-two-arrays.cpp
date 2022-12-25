#define ll long long
class Solution {
public:
    
    ll gcd(ll a,ll b)
    {
        if(b==0)
            return a;
        
        return gcd(b,a%b);
    }
    
    ll findLcm(ll x,ll y)
    {
        return (x*y)/gcd(x,y);
    }
    
    int minimizeSet(int d1, int d2, int ct1, int ct2) {
        int st=1,en=INT_MAX,ans;
        
        ll lcm=findLcm(d1,d2);
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(ct1<= mid - mid/d1 && ct2<= mid - mid/d2 && ct1+ct2 <= mid- mid/lcm)
            {
                ans=mid;
                en=mid-1;
            }
            else
                st=mid+1;
        }
        
        return ans;
        
    }
};