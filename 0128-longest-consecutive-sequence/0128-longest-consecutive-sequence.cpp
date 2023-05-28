class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i]-1)==mp.end()){  //to check whether number just less than 1 is present or not
          int ans1=1;
            //int j=i;
            int v=1; // for serial sequence
            while(true){
                if(mp.find(nums[i]+v)==mp.end()) break;
                ans1+=1;
                //j+=1;
                v+=1;
            }
            ans = std::max(ans,ans1);
        }
        
    }
    return ans;
}
};