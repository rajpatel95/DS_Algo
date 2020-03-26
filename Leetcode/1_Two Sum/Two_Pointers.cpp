using namespace std;
class Solution {
public:
    
    // Using Sort and Two-pointer approach, Complexity becomes O(N * Log (N)) 
    
    typedef struct Pair{
        int value;
        int index;
        
        Pair(int a, int b){
            value = a;
            index = b;
        }
        
        friend bool operator<(Pair a, Pair b) {
        
            return a.value < b.value;
        }
        
    };
    
 
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<Pair> pairs;
        vector<int> ans;
        
        if(nums.size() == 0){
            return ans;
        }
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            Pair temp = Pair(nums[i], i);
            pairs.push_back(temp);
        }
        
        
        sort(pairs.begin(), pairs.end());
        
        
        // Now comes the two pointers
        int p1 = 0;
        int p2 = pairs.size() - 1;
        
        while( p1 <= p2 ){
            int sum = pairs[p1].value + pairs[p2].value;
            
            if( sum == target){
                ans.push_back(pairs[p1].index);
                ans.push_back(pairs[p2].index);
                return ans;
            }
            
            if( sum > target ){
                p2--;
            }
            
            else if( sum < target ){
                p1++;
            }
        }
        
        return ans;
          
            
        
    }
};
