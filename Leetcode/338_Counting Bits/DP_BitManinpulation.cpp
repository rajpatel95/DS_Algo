class Solution {
public:
    
    vector<int> countBits(int num) {
        vector<int> dp;
        dp.push_back(0);
        if( num == 0 ){
            return dp;
        }
        
        for( int i = 1 ; i <= num ; i++ ){
            dp.push_back( dp[i >> 1] + (i & 1) );
        }
        
        return dp;
    }
};
