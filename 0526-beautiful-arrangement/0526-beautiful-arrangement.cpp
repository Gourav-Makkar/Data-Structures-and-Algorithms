class Solution {
public:
    
    void helper(vector<int>&curr,int n,int &ans,vector<int>&vis)
    {
        int s=curr.size();
        
        if(s==n)
        {
            ans++;
            return;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(i%(s+1)==0 || (s+1)%i==0)
                {
                    curr.push_back(i);
                    vis[i]=1;
                    helper(curr,n,ans,vis);
                    
                    vis[i]=0;
                    curr.pop_back();
                }
            }
        }
            
    }
        
    int countArrangement(int n) {
        vector<int>curr;
        int ans=0;
        vector<int>vis(n+1,0);
        
        helper(curr,n,ans,vis);
        return ans;
    }
};