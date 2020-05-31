class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int tem = -1;
        int ans;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>=floor(nums.size()/2)){
                if(mp[nums[i]]>tem){
                    tem = mp[nums[i]];
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
};