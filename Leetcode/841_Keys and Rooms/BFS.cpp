class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for( int x: rooms[curr]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        
        for( int i = 0 ; i < rooms.size(); i++ ){
            if(!visited[i]){
                return false;
            }
        }
        
        return true;
    }
};
