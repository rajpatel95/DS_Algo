class Solution {
public:
    
    int findLength(vector<int>& A, vector<int>& B) {
        
        int dp[1005][1005];
        int ans = 0;
        
        for(int i = 0 ; i < A.size(); i++ ){
            for(int j = 0 ; j < B.size(); j++ ){
                dp[i][j] = 0;
            }
        }
        
        for(int i = 0 ; i < A.size(); i++){
            if(A[i] == B[0]){
                dp[i][0] = 1;
            }
        }
        
        for(int j = 0 ; j < B.size(); j++ ){
            if( B[j] == A[0] ){
                dp[0][j] = 1;
            }
        }
        
        for(int i = 1 ; i < A.size(); i++ ){
            for(int j = 1; j < B.size(); j++ ){
                if(A[i] == B[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    if(dp[i][j] > ans){
                        ans = dp[i][j];
                        
                    }
                }
            }
        }
        
        return ans;
    }
};
