class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ctz=0,cto=0,ctt=0;
        
        for(auto it:nums)
        {
            if(it==0)
                ctz++;
            else if(it==1)
                cto++;
            else
                ctt++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(ctz>0)
            {
                nums[i]=0;
                ctz--;
            }
            else if(cto>0)
            {
                nums[i]=1;
                cto--;
            }
            else
            {
                nums[i]=2;
                ctt--;
            }
        }
        
    }
};