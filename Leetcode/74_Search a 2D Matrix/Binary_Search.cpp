class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size() == 0 ){
            return false;
        }
        
        // Refer Notes For the Formula of getting Row and Col Number from given id
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int start = 0;
        int end = (rows * cols) - 1; 
        
        while( start <= end ){
            int mid = start + (end - start)/2;
            
            int pivot = matrix[mid/cols][mid%cols]; // Concept for a 2D Matrix
            
            if(pivot == target){
                return true;
            }
            else if( pivot > target ){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return false;
    }
};
