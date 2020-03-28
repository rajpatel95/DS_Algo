class Solution {
public:
    
    int cnt = 0;
    
    void recur( int temp, int total ){
        
        // Can also do return 0 for temp > total, and 1 for temp == total
        if( temp == total ){
            cnt++;
            return;
        }
        
        if( temp > total ){
            return;
        }
        
        // Could return F(temp+1, total) + F(temp+2, total)
        recur( temp + 1, total );
        
        recur( temp + 2, total );
    }
    
    int climbStairs(int n) {
        
        if( n == 0 || n == 1 ){
            return n;
        }
        
        recur(0, n);
        return cnt;
        
    }
};
