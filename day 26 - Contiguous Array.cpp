class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // int n;
        // cin>>n;
        // for (int i = 0; i < n; ++i)
        // {
        //     int no;
        //     cin>>no;
        //     nums.push_back(no);
        //     /* code */
        // }

        int preCnt = 0, ans = 0;
        unordered_map<int,int> mapping;
        mapping[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            preCnt += nums[i] ? 1 : -1;
            // cout<<preCnt<<" "<<mapping.count(preCnt)<<nl;
            if (mapping.count(preCnt))
                ans = max(ans, i - mapping[preCnt]);
            else mapping[preCnt] = i;
            // cout<<mapping.count(preCnt)<<nl;
        }

        return ans;
        // cout<<ans<<nl;
    }
};