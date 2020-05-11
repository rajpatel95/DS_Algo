class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> q;
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        if( newColor == oldColor ){
            return ans;
        }
        q.push({sr,sc});
        ans[sr][sc] = newColor;
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, 1, -1, 0};
        
        
        while( !q.empty() ){
            int queue_size = q.size();
            while(queue_size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for( int i = 0 ; i < 4 ; i++ ){
                    int x1 = x + dx[i];
                    int y1 = y + dy[i];
                    if( x1 < 0 || y1 < 0 || x1 >= image.size() || y1 >= image[0].size() || ans[x1][y1] != oldColor){
                        continue;
                    }
                    ans[x1][y1] = newColor;
                    q.push( {x1, y1} );
                }
            }
        }
        
        return ans;
    }
};
