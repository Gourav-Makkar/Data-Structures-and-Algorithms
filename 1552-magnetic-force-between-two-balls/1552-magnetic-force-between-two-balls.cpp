class Solution {
public:
     bool check(int dis,vector<int>&stalls,int cows)
    {
        int prev=stalls[0];
        cows--;
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-prev>=dis)
            {
                prev=stalls[i];
                cows--;
                if(cows==0)
                  return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& stalls, int k) {
        int n=stalls.size();
        int ans;
        sort(stalls.begin(),stalls.end());
        
        int st=1,en=stalls[n-1]-stalls[0];
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            
            if(check(mid,stalls,k))
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