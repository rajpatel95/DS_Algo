class Solution {
public:
    int countVowelStrings(int n) {
        int dp[55][5];
        
        if(n == 1){
            return 5;
        }
        else if(n == 2){
            return 15;
        }
        
        // Init DP
        for(int i = 0; i < 5; i++ ){
            dp[1][i] = 5 - i;
        }
        
        // dp[i] = Sum of all dp[i - 1]
        
        for(int i = 2; i <= n ; i++ ){
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
            dp[i][1] = dp[i][0] - dp[i - 1][0];
            dp[i][2] = dp[i][1] - dp[i - 1][1];
            dp[i][3] = dp[i][2] - dp[i - 1][2];
            dp[i][4] = dp[i][3] - dp[i - 1][3];
        }
        
        return dp[n][0];
    }
};
