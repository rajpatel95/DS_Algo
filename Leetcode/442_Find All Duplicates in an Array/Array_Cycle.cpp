class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // As 1 < a[i] <= n, check for each element's index
        
        vector<int> ans;
        
        for( int i = 0 ; i < nums.size(); i++){
            int temp = abs(nums[i]);
            
            temp -= 1; // Array is Zero indexed
           
            if(nums[temp] < 0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[temp] = -nums[temp];
            }
        }
        
        return ans;
    }
};
