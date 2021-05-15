class Solution {
public:
    
    int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
    int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};
    
    vector<pair<int, int>> allMoves(int x, int y){
        vector<pair<int, int>> moves;
        
        for( int i = 0 ; i < 8; i++ ){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            moves.push_back({x1, y1});
        }
        
        return moves;
    }
    
    int hash(int x, int y){
        return 3000 * x + y;
    }
    
    int minKnightMoves(int x, int y) {
        int ans = 0;
        
        if( x == 0 && y == 0 ){
            return ans;
        }
        
        x = abs(x);
        y = abs(y);
        
        set<int> visited;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while( !q.empty() ){
            int q_size = q.size();
            
            
            while( q_size-- ){
                pair<int, int> current = q.front();
                q.pop();
                
                if( current.first == x && current.second == y){
                    return ans;
                }
                
                vector<pair<int, int>> moves = allMoves(current.first, current.second);
                
                for( pair<int, int> x: moves ){
                    int s1 = hash(x.first, x.second);
                    
                    if( visited.find(s1) == visited.end() && x.first >= -1 && x.second >= -1){
                        visited.insert(s1);
                        q.push(x);
                    }
                   
                }

            }
            ans++;
        }
        
        return -1;
    }
};
