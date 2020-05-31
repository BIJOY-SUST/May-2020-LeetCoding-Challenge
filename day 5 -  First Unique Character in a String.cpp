class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(mp[s[i]]==1){
                ans=i;
            }
        }
        return ans;
        
    }
};