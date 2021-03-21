class Solution {
public:
    int maxSubArray(vector<int>& nums) {
 
        int dp[nums.size()];
        dp[0] = nums[0];
        int maxi = dp[0];
        
        for(int i = 1; i < nums.size(); i++){
            if( dp[i - 1] > 0 ){
                dp[i] = dp[i - 1] + nums[i];
            }
            else{
                dp[i] = nums[i];
            }
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
    }
};
