class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        int ans = INT_MAX;
        
        for(int j = 0 ; j < n ; j++ ){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i = 1 ; i < n; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                if( j == 0 ){
                    dp[i][j] = min(dp[i -1][j], dp[i - 1][j + 1]);
                    dp[i][j] += matrix[i][j];
                }
                else if( j == n - 1){
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
                    dp[i][j] += matrix[i][j];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                    dp[i][j] += matrix[i][j];
                }
            }
        }
        
        for(int j = 0 ; j < n ; j++ ){
            ans = min(ans, dp[n - 1][j]);
        }
        
        return ans;
    }
};
