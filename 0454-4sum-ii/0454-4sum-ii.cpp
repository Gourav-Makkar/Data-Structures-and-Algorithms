class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n1=nums1.size(),n2=nums2.size(),n3=nums3.size(),n4=nums4.size(),ct=0;
        
        unordered_map<int,int>m;
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
               m[nums1[i]+nums2[j]]++;
            }
        }
        
        for(int i=0;i<n3;i++)
        {
            for(int j=0;j<n4;j++)
            {
                if(m.find(-(nums3[i] + nums4[j]))!=m.end())
                {
                    ct+=m[-(nums3[i] + nums4[j])];
                    // m[-(nums3[i] + nums4[j])]--;
                    // if(m[-(nums3[i] + nums4[j])]==0)
                    //     m.erase(-(nums3[i] + nums4[j]));
                }
            }
        }
        
        return ct;
    }
};