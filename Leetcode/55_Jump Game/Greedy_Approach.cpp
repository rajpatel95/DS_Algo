class Solution {
public:


    bool canJump(vector<int>& nums) {
        
        if(nums.size() == 1 ){
            return true;
        }
        
        if( nums.size() == 0 || nums[0] == 0 ){
            return false;
        }
        
        int i = 0;
        
        while( i < nums.size() ){
            
            if( i + nums[i] >= nums.size() - 1 ){
                return true;
            }
            
                        
            if( nums[i] == 0 ){
                return false;
            }
            
            int maxi = 0;
            int jump;
            

            for( int j = 1 ; j <= nums[i] ; j++ ){
                
                if( i + j + nums[i+j] > maxi ){
                    maxi = i + j + nums[i+j];
                    jump = j;
                }
            }
        
            i += jump;

            
        }
        
        return true;
    }    
};
