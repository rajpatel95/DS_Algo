class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        set<char> myset; // Set to maintain non-repeating elements
        int left = 0, right = 0; // 2 pointers of the Window
 
        while(right < s.size()){
            
            // If the element is already present in the set, increment the starting pointer (Window size should be decreased)
            if( myset.find(s[right]) != myset.end()){
                myset.erase(s[left]);
                left++;
            }

            // If the element is not present, increment end pointer and increase the window size, and add the new element in the set
            else{
                myset.insert(s[right]);
                right++;
                if( myset.size() > maxi ){
                    maxi = myset.size();
                }
            }
        }
        
        return maxi;
    }
};
