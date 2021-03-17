class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0 , -1, 0, 1};
    
    typedef struct Point{
        int x;
        int y;
        
    };
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        queue<Point> q;
        for( int i = 0 ; i < grid.size(); i++ ){
            for( int j = 0 ; j < grid[0].size(); j++ ){
                if( grid[i][j] == '1'){
                    ans++;
                    Point point_intitial;
                    point_intitial.x = i;
                    point_intitial.y = j;
                    q.push(point_intitial);
                    
                    while(!q.empty()){
                        Point point = q.front();
                        q.pop();
                        
                        for( int i = 0 ; i < 4; i++ ){
                            int x1 = point.x + dx[i];
                            int y1 = point.y + dy[i];
                            
                            if( x1 >= 0 && y1 >= 0 && x1 < grid.size() && y1 < grid[0].size() && grid[x1][y1] == '1'){
                                grid[x1][y1] = '0';
                                Point point_temp;
                                point_temp.x = x1;
                                point_temp.y = y1;
                                
                                q.push(point_temp);
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
