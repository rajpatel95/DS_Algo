class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        
        // Intialize with zeros
        for( int i = 0 ; i < A.size(); i++ ){
            ans.push_back(0);
        }
        
        int start = 0, end = A.size() - 1;
        
        while( start <= end ){
            if( A[start] * A[start] >= A[end] * A[end]){
                ans[end-start] = A[start] * A[start];
                start++;
            }
            else{
                ans[end-start] = A[end] * A[end];
                end--;
            }
        }
        
        return ans;
    }
};
