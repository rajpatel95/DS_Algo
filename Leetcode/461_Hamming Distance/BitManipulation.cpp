class Solution {
public:
    int hammingDistance(int x, int y) {
        // Count Number of Set bits in XOR
        int ans = 0;
        int xor_1 = x ^ y;
            
        while( xor_1 != 0 ){
            
            // Check if LSB is one i.e. LSB of both numbers is different
            if( xor_1 & 1 ){
                ans++;
            }
            // Right shift, and check for rest of the bits
            xor_1 >>= 1;
        }
        
        return ans;
    }
};
