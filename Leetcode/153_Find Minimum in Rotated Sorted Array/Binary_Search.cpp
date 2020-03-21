class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if( nums.size() == 1 ){
            return nums[0];
        }

        if( nums.size() == 2 ){
            return min(nums[0],nums[1]);
        }
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end){
            int mid = (start + end) / 2;

            if( (mid - 1) >= 0 && nums[mid-1] > nums[mid]){
                return nums[mid];
            }

            if( nums[mid] < nums[0] ){
                end = mid - 1;
            }
            else if( nums[mid] > nums[0] ){
                start = mid + 1;
            }
            else{
                break;
            }
            
        }
        return min(nums[0],nums[1]);
    }
};
