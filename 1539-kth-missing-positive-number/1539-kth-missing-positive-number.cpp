class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int st=0,en=n-1;
        
        if(k<arr[0])
            return k;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            if(arr[mid]-(mid+1)<k)
                st=mid+1;
            else
                en=mid-1;
        }
        
        // if(st>=n)
        //     return arr[en]+k;
        
        return arr[en]+(k-(arr[en]-en-1));
    }
};