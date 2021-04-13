class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int rows, cols;
    
    string direction[4] = {"l","r","u","d"};
    
    set<string> st;
    
    void recur(vector<vector<int>>& grid, int x, int y, string& dir){
        if( x >= rows || y >= cols || x < 0 || y < 0 || grid[x][y] == 0 ){
            return;
        }
        // If Valid and no land body
        
        grid[x][y] = 0; // Visited this island, no need to visit again
        
        for( int i = 0 ; i < 4 ; i++ ){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            dir += direction[i];
            recur(grid, x1, y1, dir); // DFS for 4 surrounding sides
                
        }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        rows = grid.size();
        if( rows == 0 ){
            return 0;
        }
        int cnt = 0;
        
        cols = grid[0].size();
        
        for( int i = 0 ; i < rows ; i++ ){
            for( int j = 0 ; j < cols ; j++ ){
                if(grid[i][j] == 1){
                    string temp = "";
                    recur(grid, i, j, temp);
                    
                    if(st.find(temp) == st.end()){
                        st.insert(temp);
                        cnt++;
                    }
                    
                }
            }
        }
        
        return cnt;
    }
};
