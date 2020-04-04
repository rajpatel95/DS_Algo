class Solution {
public:
    

    bool visited[210][210];
    
    void initVisit(int rows, int cols){
        for( int i = 0 ; i < rows; i++ ){
            for( int j = 0 ; j < cols; j++ ){
                visited[i][j] = false;
            }
        }
    }

    bool recur(int i, int j, string word, int index, vector<vector<char>>& board ){
        
        // If parsed all indices of word, then word must be there
        if( index == word.length() ){
            return true;
        }
        
        if( i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] ||
           board[i][j] != word[index] ){
            return false;
        }
        
        
        visited[i][j] = true;
    
         if(recur( i , j+1, word, index + 1, board) ||
                recur(i , j-1, word, index + 1, board) ||
                recur(i+1 , j, word, index + 1, board) ||
                recur(i-1 , j, word, index + 1, board)){
             return true;
         }
             
        
        visited[i][j] = false;
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.size() == 0 ){
            return false;
        }
        
        initVisit(board.size(), board[0].size());
        
        for( int i = 0 ; i < board.size() ; i++ ){
            for( int j = 0 ; j < board[0].size() ; j++ ){
                
                if( board[i][j] == word[0] ){
                    //cout<<i<<":"<<j;
                    if( recur(i, j, word, 0, board) ){
                        return true;
                    }
                }

            }
        }
        return false;
    }
};
