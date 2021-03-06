class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60,0);
        int ans = 0;
        
        for( int x: time){
            freq[x % 60]++;
        }
        
        
        for( int i = 0 ; i <= 30; i++ ){
            if( i == 0 || i == 30 ){
                if(freq[i] >= 2){
                    ans += ((freq[i])*(freq[i] - 1))/2;
                }
            }
            else{
                ans += freq[i]*freq[60-i];
            }
            
        }
        
        
        return ans;
    }
};
