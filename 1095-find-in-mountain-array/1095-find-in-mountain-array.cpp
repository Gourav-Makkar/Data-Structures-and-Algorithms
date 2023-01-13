/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
     int first(int target, MountainArray &mountainArr,int st,int en)
    {
        int n=mountainArr.length();
        int ans=-1;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            int ele=mountainArr.get(mid);
            
            if(ele==target)
            {
                ans=mid;
                en=mid-1;
            }
            else if(ele<target)
            {
                if(mid==n-1 || mountainArr.get(mid+1)<ele)
                    en=mid-1;
                
                else if(mid==0 || mountainArr.get(mid-1)<ele)
                    st=mid+1;
            }
            else
            {
                en=mid-1;
            }
        }
        return ans;
    }
    int last(int target, MountainArray &mountainArr,int st,int en)
    {
        int n=mountainArr.length();
        int ans=-1;
        
        while(st<=en)
        {
            int mid=st+(en-st)/2;
            int ele=mountainArr.get(mid);
            
            if(ele==target)
            {
                ans=mid;
                en=mid-1;
            }
            else if(ele<target)
            {
                if(mid==n-1 || mountainArr.get(mid+1)<ele)
                    en=mid-1;
                
                else if(mid==0 || mountainArr.get(mid-1)<ele)
                    st=mid+1;
            }
            else
            {
                st=mid+1;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        
        int l=last(target,mountainArr,0,n-1);
        int f=first(target,mountainArr,0,n-1);
        
        if(l==-1)
            return f;
        if(f==-1)
           return l;
        return min(f,l);
    }
};