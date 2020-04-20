class Solution {
public:
     // DP
    
    int minimum(int a, int b, int c ){
        a = a > b ? b : a;
        return a > c ? c : a;
    }
    

    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int maxi = 0;
        if( matrix.size() == 0 ){
            return 0;
        }
        int dp[matrix.size() + 1][matrix[0].size() + 1];
        
        for( int i = 0 ; i < matrix.size() + 1 ; i++){
            for( int j = 0 ; j < matrix[0].size() + 1 ; j++ ){
                dp[i][j] = 0;
            }
        }
        
        
        
        for( int i = 0 ; i < matrix.size()  ; i++ ){
            for( int j = 0 ; j < matrix[0].size()  ; j++){
                if( matrix[i][j] == '1'){
                    dp[i+1][j+1] = minimum(dp[i][j], dp[i][j+1], dp[i+1][j]) + 1;
            
                    if( dp[i+1][j+1] > maxi ){
                        maxi = dp[i+1][j+1];
                    }
                }
            }
        }
        
            
        return maxi * maxi ;
    }
};
