class Solution {
    
private:
    
    typedef struct Point{
        int x;
        int y;
    };
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<Point> q;
        int ans = 0;
        
        int visited[grid.size()][grid[0].size()];
        
        for(int i = 0 ; i < grid.size(); i++ ){
            for(int j = 0; j < grid[0].size(); j++ ){
                visited[i][j] = false;
            }
        }
        
        for(int i = 0 ; i < grid.size(); i++ ){
            
            for( int j = 0; j < grid[0].size(); j++ ){
                if(!visited[i][j] && grid[i][j] == 1){
                    visited[i][j] = true;
                    Point point;
                    point.x = i;
                    point.y = j;
                    
                    q.push(point);
                    int cnt = 0;
                    
                    while( !q.empty() ){
                        Point p = q.front();
                        q.pop();
                        cnt++;
                        for(int i = 0; i < 4; i++ ){
                            int x1 = p.x + dx[i];
                            int y1 = p.y + dy[i];
                            if( x1 >= 0 && y1 >= 0 && x1 < grid.size() && y1 < grid[0].size() && !visited[x1][y1] && grid[x1][y1] == 1){
                                visited[x1][y1] = true;
                                Point p1;
                                p1.x = x1;
                                p1.y = y1;
                                q.push(p1);
                            }
                        }
                    }
                    if(cnt > ans){
                        ans = cnt;
                    }
                }
            }
        }
        
        return ans;
    }
};
