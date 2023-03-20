class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int ct) {
        int n=bed.size();
        int i=0;
        
        while(i<n)
        {
            if(bed[i]==0)
            {
                if(i==n-1 || (i!=n-1) && bed[i+1]!=1)
                {
                    ct--;
                    i+=2;
                }
                else
                    i+=3;
            }
            else
              i+=2;
        }
        return ct<=0;
    }
};