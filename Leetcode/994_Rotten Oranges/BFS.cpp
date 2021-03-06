class Solution {
public:
    
    typedef struct Point{
        int x;
        int y;
    }; 
        
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};
        
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        
        queue<Point> q;
        bool flag = true;
        int m = grid.size();
        int n = grid[0].size();
        
        for( int i = 0 ; i < m; i++ ){
            for( int j = 0 ; j < n; j++ ){
                if( grid[i][j] != 0 ){
                    flag = false;
                }
                if(grid[i][j] == 2){
                    Point point;
                    point.x = i;
                    point.y = j;
                    q.push(point);
                }
            }
        }
        if(flag){
            return 0;
        }
        
        int q_size;
        int ans = 0;
        
        while(!q.empty()){
            
            
            q_size = q.size();
            bool increment = false;
            for( int i = 0 ; i < q_size; i++){
                Point point = q.front();
                q.pop();
                
                for( int j = 0 ; j < 4 ; j++ ){
                    int x1 = point.x + dx[j];
                    int y1 = point.y + dy[j];
                    
                    if( x1 < m && y1 < n && x1 >= 0 && y1 >= 0 && grid[x1][y1] == 1){
                        Point temp_point;
                        temp_point.x = x1;
                        temp_point.y = y1;
                        q.push(temp_point);
                        grid[x1][y1] = 2;
                        increment = true;
                   
                    }
                    
                }
                
            }
            if(increment){
                ans++;
            }
            
        }
        
        for( int i = 0 ; i < m; i++ ){
            for( int j = 0 ; j < n; j++ ){
                if(grid[i][j] == 1){
                    flag = true;
                }
            }
        }
        if(flag){
            return -1;
        }
        return ans;
        
        
    }
};
