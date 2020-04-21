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
    
    // As given in Hint, if 1 is found, GO LEFT, if 0 is found, GO DOWN
    // O(M+N) time complexity, maximum calls would be 100 + 100 = 200
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        
        int ans = -1;
        int rowp = 0, colp = n - 1;
        
        while(rowp < m && colp >= 0){
            if(binaryMatrix.get(rowp, colp) == 1){
                ans = colp;
                colp--;
            }
            else{
                rowp++;
            }
        }
        
        return ans;
        
        
    }
};
