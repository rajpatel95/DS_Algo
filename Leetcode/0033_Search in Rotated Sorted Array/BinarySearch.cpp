class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int ans = -1;
        
        if( nums.size() == 0 ){
            return ans;
        }
        
        int pivot, mid, start = 0, end = nums.size() - 1;
        
        // Search Pivot index, O(Log N)
        while( start <= end ){
            mid = start + (end-start)/2;
            
            if( mid > 0 && nums[mid] < nums[mid - 1] && mid < nums.size() - 1 && nums[mid] < nums[mid + 1] ){
                pivot = mid;
                break;
            }
            
            else if( nums[mid] < nums[0] ){
                end = mid - 1;
            }
            
            else {
                start = mid + 1;
            }
    
        }
        
        
        if( target == nums[pivot] ){
            return pivot;
        }
        
        // Search in respective Left or Right side of the partitions
        if( target >= nums[0]){
            start = 0, end = pivot - 1;
        }
        else{
            start = pivot, end = nums.size() - 1;
        }
            
        while(start <= end){
                
            mid = start + (end-start)/2;
            
            if(nums[mid] == target){
                return mid;
            }
                
            else if(nums[mid] > target){
                end = mid - 1;
            }
                
            else{
                start = mid + 1;
            }
        }
        
        return ans;
    }
};
