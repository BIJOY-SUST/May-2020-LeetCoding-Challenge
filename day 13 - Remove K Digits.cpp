class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = num;
        
        if (k>=s.size())
        {
            return "0";
            /* code */
        }
        
        s+='0';
        std::vector<char> ans;

        for (int i = 0; i < s.size(); ++i)
        {
            while(!ans.empty() and s[i] < ans.back() and k){
                k--;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            /* code */
        }
        string newAns;
        for (int i = 0; i < ans.size()-1; ++i)
        {
            if (newAns.size()!=0 or ans[i]!='0')
            {
                newAns+=ans[i];
                /* code */
            }
            /* code */
        }
        if (newAns.empty())
        {
            return "0";
            /* code */
        }
        else{
            return newAns;
        }
    }
};