doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem H: Who Will Get the Nomination?

#{b.figureRight 'The political puzzle game', 'nomination.jpg', 0.38, 15}

Occasionally during presidential elections puzzles get created for campaign
purposes, some of them becoming fervidly popular, like this little game
called "The Political Puzzle Game".

It consists of a $5 \\times 5$ board, and nine pieces, each one representing
a different candidate. The object of the game is to "capture" eight of the
pieces, and leave the last one (the winner) on the square located at the
centre of the board. We are not particularly interested in which candidate
wins the game, but in doing this in the minimum number of moves possible.

A move means sliding any piece to an adjacent square, or jumping over
another piece, removing the piece that was jumped over. All moves, whether
they capture a piece or not, can be performed horizontally, vertically or
diagonally. You can capture only one piece in one move, and only if there is
a free square directly on the opposite side of the captured piece (the
landing square).

- - -

You receive a description of a board, where a number of pieces (between 1
and 9) are arbitrarily scattered throughout the board. Your task is to
determine the minimum number of moves required to win the game with any of
its pieces.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each case starts with a blank line. The next five lines contain five
characters each, and they describe the board. Each character of the board
will be either a dot (`.`) or an asterisk (`*`). Dots represent empty
squares, and asterisks represent game pieces. The number of pieces will be
always between 1 and 9 (inclusive).

#{b.constraints 'T \\leq 100'}

## Output ##

For each test case, print the case number, followed by the minimum
number of moves required to capture all pieces on the board except for one,
leaving the winner on the center of the board.

#{b.samples '''
3

.....
.***.
.***.
.***.
.....

.....
.*...
..*..
.....
.....

.....
..*..
.***.
..*..
.....
''', '''
Case 1: 8
Case 2: 2
Case 3: 5
'''}

## Explanation of Sample Cases ##

For the first case, consider enumerating the pieces as follows:

~~~
.....
.123.
.456.
.789.
.....
~~~

Then one way to solve it in eight moves can be as follows:

-   2 jumps 6.
-   5 jumps 8.
-   2 jumps 9.
-   7 jumps 2.
-   5 jumps 7.
-   5 jumps 3.
-   5 jumps 1.
-   5 jumps 4.

For the second case, the topmost piece jumps over the other, and then moves
back into the center, for a total of 2 moves.

For the third case, there is an interesting way to solve it in 5 moves,
which is left as an exercise.

"""
# |end.markdown|
