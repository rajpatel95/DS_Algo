class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        unsigned int dp[grid.size()+1][grid[0].size()+1];
        
        // Initialize first Row and Column with the sum of values until them
        dp[0][0] = grid[0][0];
        
        for( int i = 1 ; i < grid.size() ; i++ ){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        
        
        for( int j = 1 ; j < grid[0].size() ; j++ ){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // DP Step, minimum value to reach by taking 'horizontal cell left' to that or 'vertical cell above' the current cell
        for( int i = 1 ; i < grid.size() ; i++ ){
            for( int j = 1 ; j < grid[0].size() ; j++ ){
                dp[i][j] = min(grid[i][j] + dp[i][j-1],
                              grid[i][j] + dp[i-1][j]);   
            }
        }

        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
