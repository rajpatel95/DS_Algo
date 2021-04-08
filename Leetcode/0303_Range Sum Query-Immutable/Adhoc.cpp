class NumArray {
public:
    vector<int> arr;
    vector<int> sums;
    
    NumArray(vector<int>& nums) {
        arr = nums;
        int sum = nums[0];
        sums.push_back(sum);
        
        for(int i = 1 ; i < nums.size(); i++ ){
            sum += nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        
        if( left == 0 ){
            return sums[right];
        }
        return sums[right] - sums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
