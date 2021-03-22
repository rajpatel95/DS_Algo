class Solution {
public:
    
    int findMappedValue(int value){
        int power =  log2(value); //  OR, log(value)/log(2), anyone's fine
        
        int start = pow(2, power);
        int end = start * 2 - 1;
        
        return end - (value - start);
    }
    
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;

        while(label != 0){
            ans.push_back(label);
            label = findMappedValue(label); // Because, every alternate level has reversed value than the current, so we can find mapped for every level
            label /= 2;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    
};
