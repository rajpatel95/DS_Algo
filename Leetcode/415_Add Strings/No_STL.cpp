class Solution {
public:

    // Time Complexity is Optimal and can't be reduced. O(N), where N is the size of the larger number
    // Possible to reduce execution time by using STL
    
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        string ans;
        
        for( int i = 0 ; i < 5101 ; i++ ){
            ans += '0';
        }
        

        int nums = 5100;
        
        while( i >= 0 || j >= 0 ){
            int sum ;
            
            int n1 = i >= 0 ? (num1[i] - '0') : 0;
            int n2 = j >= 0 ? (num2[j] - '0') : 0;
            
            sum = (n1) + (n2) + carry;
            
            carry = sum / 10;
            sum %= 10;
    
            ans[nums] = sum + '0';

            j--;
            i--;
            nums--;
            
        }
        
        ans[nums]  = carry + '0';
        
        return ans.substr(nums + 1 - carry,5100);
    }
};
