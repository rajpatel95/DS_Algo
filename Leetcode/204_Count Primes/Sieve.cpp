class Solution {
public:
    int countPrimes(int n) {
        // Sieve
        
        vector<int> table(n, 0); // 1 means prime, 2 is non-prime
        int ans = 0;
        for( int i = 2 ; i < n ; i++ ){
            if( table[i] == 0 ){ // Check if element has been visited
                table[i] = 1;
            }
            else{
                continue; // If element is already visited, go ahead
            }
            
            for( int j = 2 ; i * j < n ; j++ ){
                table[i * j] = 2;
            }
            
        }
        for( int i = 2 ; i < n ; i++ ){
            if( table[i] == 1 ){
                ans++;
            }
        }
        
        return ans;
    }
};
