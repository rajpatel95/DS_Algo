class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 1){
            return true;
        }
        bool flag;
        
        int i = 1;
        
        while(A[i] == A[i-1] ){
            
            if(i == A.size() - 1){
                return true;
            }
            i++;
        }
        
        if(A[i] > A[i-1]){
            flag = true;
        }
        else{
            flag = false;
        }
        
        for(; i < A.size(); i++){
            if(flag && A[i] < A[i - 1]){
                return false;
            }
            else if(!flag && A[i] > A[i -1]){
                return false;
            }
        }
        
        return true;
        
    }
};
