class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t i = 1;
        int j = 0;
        while(j < 32){
            
            if(n & i){
                ans++;
            }
            i <<= 1;
            j++;
        }
        
        return ans;
    }
};
