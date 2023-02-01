class Solution {
public:
    int lra(vector<int> heights) {
        int n=heights.size();
        vector<int>nextsm(n);
        stack<int>st;
        
        nextsm[n-1]=n;
        st.push(n-1);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            int idx=st.empty()?n:st.top();
            nextsm[i]=idx;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        vector<int>prevsm(n);
        prevsm[0]=-1;
        st.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            int idx=st.empty()?-1:st.top();
            prevsm[i]=idx;
            st.push(i);
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int prev=prevsm[i];
            int next=nextsm[i];
            
            ans=max(ans,(next-prev-1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>mat(r,vector<int>(c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                mat[i][j]=matrix[i][j]-'0';
        }
        
        int ans=lra(mat[0]);
        
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]!=0)
                    mat[i][j]+=mat[i-1][j];
            }
            ans=max(ans,lra(mat[i]));
        }
        return ans;
        
    }
};