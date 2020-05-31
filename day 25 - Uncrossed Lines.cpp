class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {

        if (A.size() == 0 || B.size() == 0) {
            return 0;
        }

        int n = A.size();
		int m = B.size();

        int dp[n+1][m+1];
        for (int i = 0; i <= n; ++i)
        {
        	for (int j = 0; j <= m; ++j)
        	{
        		dp[i][j]=0;
        	}
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }
};