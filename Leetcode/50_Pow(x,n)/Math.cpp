class Solution {
public:
    double myPow(double x, int n) {
        
        if( n == 0 ){
            return 1;
        }
        
        // Edge cases and negative exponents
        long num;
        if( n > 0 ){
            num = n;
        }
        else{
            num = n;
            num = -num;
        }
        double ans;
        
        if( n > 0){
            ans = power(x, num);
        }
        else{
            ans = 1/power(x, num);
        }
        
        return ans;
    }
    
    // This is the actual function, that takes O(Log N) time
    double power(double x, long long int n){
        
        if( n == 1){
            return x;
        }
        
        if( n % 2 == 0 ){
            return power( x * x, n/2);
        }
        else{
            return x * power( x * x, n/2);
        }
        
        return 1;
    }
};
