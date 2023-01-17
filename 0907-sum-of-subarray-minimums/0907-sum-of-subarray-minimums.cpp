class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        
        vector<int>nextSm(n);
        stack<int>st;
        st.push(n-1);
        nextSm[n-1]=n;
        
        // Next smaller element
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            int idx=(st.empty())?n:st.top();
            nextSm[i]=idx;
            
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        // Previous Smaller element
        vector<int>prevSm(n);
        st.push(0);
        prevSm[0]=-1;
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            int idx=(st.empty())?-1:st.top();
            prevSm[i]=idx;
            
            st.push(i);
        }
        
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            cout<<nextSm[i]<<" "<<prevSm[i]<<endl;
            
            long long ct=(i-prevSm[i])*(nextSm[i]-i);
            ans+=(ct*arr[i]);
            ans=ans%1000000007;
        }
        
        return ans;
    }
};