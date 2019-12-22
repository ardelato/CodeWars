# Matrix Addition
Write a function that accepts two square matrices (`N x N` two dimensional arrays), and return the sum of the two. Both matrices being passed into the function will be of size `N x N` (square), containing only integers.

How to sum two matrices:

Take each cell `[n][m]` from the first matrix, and add it with the same `[n][m]` cell from the second matrix. This will be cell `[n][m]` of the solution matrix.

Visualization:
``` C
   A B C        A B C
1 |1 2 3|    1 |2 2 1|     |(A1+A1) (B1+B1) (C1+C1)|  =  |1+2 2+2 3+1|     |3 4 4|
2 |3 2 1|  + 2 |3 2 3|  =  |(A2+A2) (B2+B2) (C2+C2)|  =  |3+3 2+2 1+3|  =  |6 4 4|
3 |1 1 1|    3 |1 1 3|     |(A3+A3) (B3+B4) (C3+C3)|  =  |1+1 1+1 1+3|     |2 2 4|
```
### Example
``` C
matrixAddition(
  [ [1, 2, 3],
    [3, 2, 1],
    [1, 1, 1] ],
//      +
  [ [2, 2, 1],
    [3, 2, 3],
    [1, 1, 3] ] )

// returns:
  [ [3, 4, 4],
    [6, 4, 4],
    [2, 2, 4] ]
```