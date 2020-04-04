class Solution {
public:
    
    // Use Same logic as Word Search, Number of Islands(DFS and Backtracking), Try to remember the basic template
    
    bool visited[20][20];
    int maxi;
    
    void initVisit(int m, int n){
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                visited[i][j] = false;
            }
        }
    }
    
    
    void dfs(vector<vector<int>>& grid, int i, int j, int total){
        
        if( total >= maxi ){
            maxi = total;
        }
        
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0 ){
            return;
        }
        
        
        visited[i][j] = true;
        
        dfs(grid, i , j+1, total + grid[i][j]);
        dfs(grid, i, j-1, total + grid[i][j]);
        dfs(grid, i-1, j, total + grid[i][j]);
        dfs(grid, i+1, j, total + grid[i][j]);
        
        visited[i][j] = false; // Backtracking
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        if( grid.size() == 0 ){
            return 0;
        }
        
        initVisit(grid.size(), grid[0].size());
        
        maxi = 0;
        
        for( int i = 0 ; i < grid.size() ; i++ ){
            for( int j = 0 ; j < grid[0].size() ;j++ ){
                if( grid[i][j] != 0 ){
                    cout<<"IN"<<i<<":"<<j<<":"<<maxi<<endl;
                    dfs(grid, i, j, 0);
                }
            }
        }
        
        return maxi;
    }
};
