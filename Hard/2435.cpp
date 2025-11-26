class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // dp[i][j][r] = number of paths to (i,j) with sum % k = r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    if (i == 0 && j == 0) continue;
                    long long ways = 0;

                    if (i > 0) ways += dp[i - 1][j][r];
                    if (j > 0) ways += dp[i][j - 1][r];

                    int new_r = (r + grid[i][j]) % k;
                    dp[i][j][new_r] = (dp[i][j][new_r] + ways) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
