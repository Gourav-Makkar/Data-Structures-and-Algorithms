class Solution {
public:
    
    bool helper(vector<int>&arr,int idx,int n)
    {
        if(idx<0 || idx>=n || arr[idx]==-1)
            return false;
        if(arr[idx]==0)
            return true;
        
        int v=arr[idx];
        arr[idx]=-1;
        
        int front=helper(arr,idx+v,n);
        int back=helper(arr,idx-v,n);
        
        arr[idx]=v;
        
        return (front||back);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        
        return helper(arr,start,n);
    }
};