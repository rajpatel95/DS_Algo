
class Solution {
public:
    
    int mini = INT_MAX;
    
    void minimize(int sum, int x, int y, vector<vector<int>>& grid){
        
        if( sum > mini ){
            return ;
        }
        
        if( x == grid.size() - 1 && y == grid[0].size() - 1 ){
            mini = sum;
            return;
        }
        
        if( y + 1 < grid[0].size() ){
            minimize(sum + grid[x][y+1], x, y + 1, grid);
        }
        
        if( x + 1 < grid.size() ){
            minimize(sum + grid[x+1][y], x + 1, y, grid);
        }
            
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        minimize(grid[0][0], 0,0, grid);
        return mini;
    }
};
