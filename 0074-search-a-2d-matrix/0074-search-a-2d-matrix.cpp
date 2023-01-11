class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
            
        int st=0,en=r*c-1;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            int ele=matrix[mid/c][mid%c];
            
            if(ele==target)
                return true;
            else if(ele<target)
                st=mid+1;
            else
                en=mid-1;
        }
        return false;
    }
};