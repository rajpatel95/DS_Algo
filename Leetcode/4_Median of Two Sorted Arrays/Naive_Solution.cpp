class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        //Naive Solution, Not upto the Problem's HARD standard
        
        vector<double> num;
        int i = 0, j = 0;
        
        while( i < nums1.size() || j < nums2.size()){
            if(i == nums1.size() ){
                num.push_back(nums2[j++]);
            }
            else if( j == nums2.size()){
                num.push_back(nums1[i++]);
            }
            else if( nums1[i] >= nums2[j]){
                num.push_back(nums2[j++]);
            }
            else{
                num.push_back(nums1[i++]);
            }
        }
        
        if( num.size() % 2 != 0 ){
            return num[num.size()/2];
        }
        else{
            return (num[num.size()/2] + num[num.size()/2 - 1]) / 2;
        }
    }
};
