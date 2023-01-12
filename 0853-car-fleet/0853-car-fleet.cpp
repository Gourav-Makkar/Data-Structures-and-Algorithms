class Solution {
public:
    
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,double>>temp;
        
        for(int i=0;i<speed.size();i++)
        {
            temp.push_back({position[i],(target-position[i])/(double)(speed[i])});
        }
        
        sort(temp.begin(),temp.end());
                           
        double mx=0;
        int ct=0;
        for(int i=n-1;i>=0;i--)
        {
            if(temp[i].second>mx)
            {
                mx=temp[i].second;
                ct++;
            }
        }
        return ct;
    }
};