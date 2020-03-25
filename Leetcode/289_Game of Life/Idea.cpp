class Solution {
public:
    
    int rows,cols;
    int dx[8] = { -1, 0, 1, 0, 1, -1, 1, -1 };
    int dy[8] = { 0, -1, 0, 1, -1, 1, 1, -1 };
    
    bool isValid(int a, int b){
        if( a < 0 || b < 0 || a >= rows || b >= cols ){
            return false;
        }
        return true;
    }
    
    int checkAlive(vector<vector<int>>& board, int a, int b){
        int cnt = 0;
        
         for( int i = 0 ; i < 8 ; i++ ){
            if(isValid(a + dx[i], b + dy[i])){
                if( board[a + dx[i]][b + dy[i]] == 1 || board[a + dx[i]][b + dy[i]] == -1  ){
                    cnt++;
                }
            }
        } 

        return cnt;       
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        if( board.size() == 0 ){
            return;
        }
        rows = board.size();
        cols = board[0].size();


        for( int i = 0 ; i < rows; i++ ){
            for( int j = 0 ; j < cols ; j++ ){
                if( board[i][j] == 0 ){
                    if( checkAlive(board,i, j) == 3 ){
                        board[i][j] = 2; // 2 means Dead is Alive Now
                    }
                }
                else if( board[i][j] == 1 ){
                    if( checkAlive(board, i, j) < 2 || checkAlive(board, i, j) > 3  ){
                        board[i][j] = -1; // -1 means Alive is Dead Now
                    }
                }
            }
        }

        // Final Update on the Board
        for( int i = 0 ; i < rows; i++ ){
            for( int j = 0 ; j < cols ; j++ ){
                if(board[i][j] == -1){
                    board[i][j] = 0;
                }
                else if( board[i][j] == 2 ){
                    board[i][j] = 1;
                }
            }
        }

    }
};
