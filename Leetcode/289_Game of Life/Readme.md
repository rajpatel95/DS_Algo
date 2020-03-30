Approach 1: Space: O(M+N)  
Naive Solution is very simple. Make a copy of the board and Solve for all 8 directions for every cell.
But space Complexity would be O(M+N) extra space required.

Approach 2: Space: O(1)
(Hint Courtesy: Problem's Solution)
So, the Key here would be for First pass, change the value of the cell to be converted from 0 --> 1, into (-1) as of Now.
Similarly , Modify the Value of 1 --> 0, into (+2).

Then, in the last pass, modify the cells with Value (-1) into 0 and (+2) into 1. 
The Space complexity of this approach would be O(1).
