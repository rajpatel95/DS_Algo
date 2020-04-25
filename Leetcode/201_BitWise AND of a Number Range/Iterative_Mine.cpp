class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        if( m == 0 ){
            return 0;
        }
        
        // Checking if both the numbers fall within the same powers of 2 range
        if( (m & n) < (n >> 1) ){
            return 0;
        }
        
        // Edge case
        if( m == n ){
            return m;
        }
        
        int ans = m;
        int i = m + 1;
        while( i <= n ){
            ans &= i;
            
            //Edge case
            if( i == n ){
                break;
            }
            i++;
        }
        return ans;
    }
};
