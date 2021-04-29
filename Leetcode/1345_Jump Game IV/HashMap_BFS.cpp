class Solution {
public:
    int minJumps(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        
        queue<int> q;
        
        q.push(0);
        vector<bool> visited(arr.size(), false);
        visited[0] = true;
        
        for(int i = 0 ; i < arr.size(); i++ ){
            mp[arr[i]].push_back(i);
        }
        

        while( !q.empty() ){
            int q_size = q.size();
            ans++;
            
            while( q_size-- ){
                int current = q.front();
                q.pop();
                
                
                if(current == arr.size() - 1){
                    return ans - 1;
                }

                if( current - 1 >= 0 && !visited[current - 1]){
                    q.push(current - 1);
                    visited[current - 1] = true;
                    
                }
                if( current + 1 < arr.size() && !visited[current + 1]){
                   
                    q.push(current + 1);
                    visited[current + 1] = true;
                    
                }
                
                
                for(int i = 0 ; i < mp[arr[current]].size(); i++ ){
                    if(mp[arr[current]][i] != current && !visited[mp[arr[current]][i]]){
            
                        if(mp[arr[current]][i] == arr.size() - 1){
                            return ans;
                        }
                        q.push(mp[arr[current]][i]);
                        visited[mp[arr[current]][i]] = true;
                    }
                }
                mp.erase(arr[current]); // This is very important to save time
                
            }
            
        }
        
        return - 1;
    }
};
