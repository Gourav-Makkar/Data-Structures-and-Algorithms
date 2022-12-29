//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &as) {
        // code here
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(as[i]);
                continue;
            }
            bool flag=false;
            if(st.top()<0 && as[i]>0)
            {
              while(!st.empty() && st.top()<0 && as[i]>0)
              {
                if(abs(st.top())<as[i])
                {
                    st.pop();
                    flag=true;
                }
                else if(abs(st.top())>as[i])
                {
                    flag=false;
                    break;
                }
                else
                  {
                    st.pop();
                    flag=false;
                    break;
                  }
              }
            }
           else
             st.push(as[i]);
             
           if(flag)
             st.push(as[i]);
               
            
        }
        
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends