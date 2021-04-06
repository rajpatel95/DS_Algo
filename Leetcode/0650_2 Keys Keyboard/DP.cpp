class Solution {
public:
    int minSteps(int n) {
        int dp[1005];
        
        dp[1] = 0;
        
        for(int i = 2 ; i <= n; i++ ){
            dp[i] = i;
            for(int j = 2; j <= sqrt(i); j++ ){
                if( i % j == 0){
                    dp[i] = min(dp[i], dp[j] + dp[i / j]);
                }
            }
        }
        return dp[n];
    }
};
