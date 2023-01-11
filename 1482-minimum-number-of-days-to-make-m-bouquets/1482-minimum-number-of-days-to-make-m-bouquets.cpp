class Solution {
public:
    
    bool check(int mxDay,vector<int>&arr,int m,int k)
    {
        int ct=0;
        int f=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>mxDay)
            {
                f=0;
            }
            else{
                f++;
                if(f==k)
                {
                    ct++;
                    f=0;
                }
            }
        }
        return ct>=m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int st=INT_MAX,en=INT_MIN;
        
        for(auto it:bloomDay)
        {
            st=min(st,it);
            en=max(en,it);
        }
        
        int ans=-1;
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(mid,bloomDay,m,k))
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