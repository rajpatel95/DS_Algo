class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        
        while( X != Y ){
            if(Y % 2 != 0 || X > Y){
                Y++;
            }
            else{
                Y /= 2;
            }
            ans++;
        }
        return ans;
        
    }
};
