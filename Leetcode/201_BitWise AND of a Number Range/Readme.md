Approach 1: (Found in Most tutorials and answers):
Nice Question on Bit Manipulation. Main thing is to find the pattern and the need of 'Right Shift/Dividing by 2' the numbers.

Approach 2: (Mine, Similar but easier to understand and code)<br>
A pattern to observe is that if the given two numbers have a power of 2 in between, then the answer will always be 'zero'.<br>
Example: 5,7 are within the same power range of 2 ( 4~8 ).<br> While 10 and 20 have a power of 2 (16) in between. As, we start iterating from 10, we will hit 16, where every bit from 'BitWise AND' 10-15 will become 0, so overall AND will be zero.

