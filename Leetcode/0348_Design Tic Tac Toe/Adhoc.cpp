class TicTacToe {
public:
    /** Initialize your data structure here. */
    int rowA[105];
    int rowB[105];
    int colA[105];
    int colB[105];
    int diagA, diagB, revdiagA, revdiagB;
    int size;
    
    TicTacToe(int n) {
        size = n;
        for(int i = 0 ; i < n ; i++ ){
            rowA[i] = 0;
            rowB[i] = 0;
            colA[i] = 0;
            colB[i] = 0;
        }
        diagA = 0, diagB = 0, revdiagA = 0, revdiagB = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
       
        if(player == 1){
            
            rowA[row]++;
            colA[col]++;
            

            if( row == col ){
                
                diagA++;
                
            }
            
            if( row + col ==  size - 1 ){
                
                revdiagA++;
               
            }
            
            if( (rowA[row] == size) || (colA[col] == size) || (diagA == size) || (revdiagA == size) ){
                return 1;
            }
        }
        else if(player == 2){
            rowB[row]++;
            colB[col]++;
            
            if( row == col ){
                diagB++;
            }
            
            if( row + col ==  size - 1 ){
                revdiagB++;
                
            }
            
            if( (rowB[row] == size) || (colB[col] == size) || (diagB == size) || (revdiagB == size ) ){
                return 2;
            }
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
