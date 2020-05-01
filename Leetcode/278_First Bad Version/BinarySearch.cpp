// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        int start = 1;
        int end = n;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isBadVersion(mid) && mid > 1 && !isBadVersion(mid-1)){
                return mid;
            }
            if(isBadVersion(mid) && mid == 1 ){
                return 1;
            }
            if( isBadVersion(mid) && isBadVersion(mid-1)){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return n;
    }
};
