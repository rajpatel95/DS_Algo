class Solution {
public:
    
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_oranges = 0;
        queue<pair<int, int>> q;
        int days = 0;
        
        // Count Number of Fresh Oranges and Push Rotten ones into the Queue
        for( int i = 0 ; i < grid.size() ; i++ ){
            for( int j = 0 ; j < grid[0].size() ; j++){
                if( grid[i][j] == 1 ){
                    fresh_oranges++;
                }
                else if( grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
    
        int fresh_rotten = 0; // Count of oranges who were converted from Fresh to Rotten
        if( fresh_oranges == fresh_rotten ){
            return 0;
        }
        
        while( !q.empty() ){
            // Number of Fresh Oranges who will be Rotten after this day, Queue size indicates number of Fresh Oranges
            int queue_size = q.size();
            
            while(queue_size--){
                int a = q.front().first;
                int b = q.front().second;
                
                q.pop();
                
                for( int i = 0 ; i < 4 ; i++ ){
                    int x = a + dx[i];
                    int y = b + dy[i];
                    if( x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1){
                        continue;
                    }
                    grid[x][y] = 2; // Fresh is Rotten Now
                    fresh_rotten++;
                    q.push( {x, y} );
                }
            }
            days++;
        }
        // If all fresh oranges have been converted
        if( fresh_oranges == fresh_rotten ){
            return days - 1;
        }
        return -1;
    }
};
