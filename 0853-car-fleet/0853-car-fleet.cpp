class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({position[i],(target-position[i])/(double)speed[i]});
        }
        
        stack<double>st;
        sort(v.begin(),v.end());
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
                st.push(v[i].second);
            else
            {
                if(st.top()<v[i].second)
                    st.push(v[i].second);
            }
        }
        return st.size();
    }
};