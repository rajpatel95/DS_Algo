class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& ans, int a, int b, int newColor, int oldColor){
        for( int i = 0 ; i < 4 ; i++ ){
            int x = a + dx[i];
            int y = b + dy[i];
            
            if( x >= 0 && y >= 0 && x < ans.size() && y < ans[0].size() && ans[x][y] == oldColor){
                ans[x][y] = newColor;
                dfs(ans, x, y, newColor, oldColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ans = image;
        int fillColor = image[sr][sc];
        if( newColor == fillColor){
            return ans;
        }
        ans[sr][sc] = newColor;
        dfs(ans, sr, sc, newColor, fillColor);
        return ans;
        
    }
};
