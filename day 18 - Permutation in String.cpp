class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int counts[260]={0};
        for (char c : s1) {
            ++counts[c];
        }
        int len = s1.length();
        int dfdf = 5;
        // cout<<dfdf--<<nl;

        // cout<<++dfdf<<nl;
        for (int i = 0; i < s2.length(); ++i) {
            // cout<<"a "<<counts[s2[i]]<<nl;

            if (counts[s2[i]] > 0) {
                --len;
                // cout<<"dhukse"<<nl;
                // counts[s2[i]]--;
            }
            counts[s2[i]]--;
            // cout<<"b "<<counts[s2[i]]<<nl;
            if (len == 0) {
                return true;
            }
            int start = i + 1 - s1.length();
            if (start>=0)
            {

                counts[s2[start]]++;

                if (start >= 0 && counts[s2[start]] > 0) {
                    ++len;
                    // cout<<"dhukse porertate"<<nl;

                }
            }
            // counts[s2[start]]++;
            // cout<<"c "<<counts[s2[start]] <<" "<<start<<nl;
            // cout<<"d "<<counts[s2[start]]<<nl;
            // cout<<i<<" "<<len<<nl;
        }
        return false;
    }
};