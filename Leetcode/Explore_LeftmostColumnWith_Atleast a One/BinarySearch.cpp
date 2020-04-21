/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int binSearchRow(BinaryMatrix &binaryMatrix, int row_number, int col_end){
        int start = 0, end = col_end, mid;
        
        while(start <= end){
            mid = start + (end-start)/2;
            
            if( binaryMatrix.get(row_number, mid) == 0 ){
                start = mid + 1;
                continue;
            }
            else {
                if( mid == 0 ){
                    return mid;
                }
                else if (binaryMatrix.get(row_number, mid - 1) == 0) {
                    return mid;
                }
            }
            end = mid;
        }
        
        return -1;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        
        int ans = -1, mini = n;
        
        for( int i = 0 ; i < m ; i++ ){
            int temp = binSearchRow(binaryMatrix, i, mini - 1);
            if( temp == -1){
                continue;
            }
            else{
                mini = min(mini, temp);
                ans = mini;
            }
        }
        
        return ans;
        
        
    }
};
