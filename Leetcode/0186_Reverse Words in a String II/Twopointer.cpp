class Solution {
public:
    
    void reverseString(vector<char>& arr, int start, int end){
        while(start < end){
            swap(arr[start++], arr[end--]);
        }
    }
    
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int start = 0, end = 0;
        
        while(end < s.size()){
            
            if(s[end] == ' ' || end == s.size() - 1){
                if(end == s.size() - 1){
                    reverseString(s, start, end);
                    break;
                }
                else{
                    reverseString(s, start, end - 1);
                    end++;
                    start = end;
                }
                
            }
            else{
                end++;
            }
        }
    }
};
