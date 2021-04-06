class Solution {
public:

    int maxAbsoluteSum(vector<int>& nums) {
        
        if(nums.size() == 1){
            return abs(nums[0]);
        }
        
        int maxi = nums[0], mini = nums[0];
        int dp1[nums.size()], dp2[nums.size()];
        dp1[0] = nums[0], dp2[0] = nums[0];
        
        for(int i = 1 ; i < nums.size(); i++ ){
            dp1[i] = max(dp1[i - 1] + nums[i], nums[i]);
            dp2[i] = min(dp2[i - 1] + nums[i], nums[i]);
            
            maxi = max(dp1[i], maxi);
            mini = min(dp2[i], mini);
        }
        
        return max(maxi, abs(mini));
    }
};
