class Solution {
public:
    //O(N^2) based solution, think of O(N) time and auxillary space using HashMap
    
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for( int i = 0 ; i < nums.size() ; i++ ){
            int temp = nums[i];
            if( temp == k ){
                ans++;
            }
            for( int j = i + 1 ; j < nums.size() ; j++ ){
                temp += nums[j];
                if( temp == k ){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
