O(n2) solution is trivial. But we are asked for a better solution. 

So, there is a O(1) solution for every move() call. Trick is to store number of moves for every row/column and diagonal and reverse diagonals for both players. If at any move(), the number of reaches "N", it means that that player has won.
