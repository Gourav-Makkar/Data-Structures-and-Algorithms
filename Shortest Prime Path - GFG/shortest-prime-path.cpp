//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  
    bool isPrime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
              return false;
        }
        return true;
    }
      
    int shortestPath(int n1,int n2)
    {   
        // Complete this function using prime vector
        if(n1>n2)
          swap(n1,n2);
          
        queue<pair<int,int>>q;
        q.push({n1,0});
        vector<int>vis(10000,0);
        
        while(!q.empty())
        {
            int n=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(n==n2)
              return steps;
            
            string curr=to_string(n);
            for(int idx=0;idx<4;idx++)
            {
                string temp=curr;
                for(int i=0;i<=9;i++){
                    if(idx==0 && i==0)
                     continue;
                    
                    temp[idx]=i+'0';
                    
                    int x=stoi(temp);
                    if(isPrime(x) && vis[x]==0)
                      {
                          q.push({x,steps+1});
                          vis[x]=1;
                      }
                }
            }
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends