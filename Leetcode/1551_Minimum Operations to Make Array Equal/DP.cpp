class Solution {
public:
    // See some test cases and then easy peasy DP
    int minOperations(int n) {
        int dp[n + 1];
        
        dp[1] = 0;
        
        for( int i = 2, cnt = 2 ; i <= n ; i++, cnt++ ){
           
            dp[i] = dp[i - 1] + (cnt / 2);
        }
        
        return dp[n];
    }
};
