class Solution {
public:
    
    typedef struct Days{
        int temperature;
        int warmer_days;
    };
    
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        stack<Days> st;
        
        Days day[T.size()];
        
        for( int i = T.size() - 1 ; i >= 0 ; i-- ){
            day[i].temperature = T[i];
            day[i].warmer_days = 0;
            while( !st.empty() && st.top().temperature <= T[i] ){
                day[i].warmer_days += st.top().warmer_days;
                st.pop();
            }
            if( !st.empty() ){
                day[i].warmer_days += 1;
            }
            else{
                day[i].warmer_days = 0;
            }
            st.push(day[i]);
            
        }
        
        for( int i = 0 ; i < T.size() ; i++ ){
            ans.push_back(day[i].warmer_days);
        }
        
        
        return ans;
    }
};
