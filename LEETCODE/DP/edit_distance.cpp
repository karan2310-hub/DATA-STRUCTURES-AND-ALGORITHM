class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        for (int i = 0; i <= m; i++)
            dp[i][0] = i;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (word2[i - 1] == word1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // Insert
                        dp[i][j - 1],     // Delete
                        dp[i - 1][j - 1]  // Replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};
