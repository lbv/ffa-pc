doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem F: The Jolly Friar's Puzzle

#{b.figureRight 'The Jolly Friars moving coins', 'friar.jpg', 0.38}

A group Jolly Friars are captivated by a puzzle presented to them. Ten coins
are placed upon the sixteen squares, so that you can readily discern ten
"even lines". An even line is a line (horizontal, vertical or diagonal)
inside the grid with a positive, even number of coins in it.

The Friars have learned that the maximum number of even lines that can be
formed on a grid with ten coins is 16. A grid with that amount of even lines
is known as an *optimal grid*. The puzzle they are trying to solve now is,
what is the minimum number of moves required to turn their current grid into
an optimal grid?

Picking up one coin and placing it on any other cell (as long as it's empty)
counts as one move.

- - -

You receive the description of several grids, each one with ten coins placed
on it arbitrarily. Solve the Jolly Friars puzzle for each grid.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case begins with a blank line, followed by four lines with four
characters each, describing a grid. Each character of the grid is either a
dot (`.`) or an asterisk (`*`) which denote an empty cell or a coin,
respectively. Every grid will have exactly ten coins.

#{b.constraints 'T \\leq 1000'}

## Output ##

For each test case, print the case number, followed by the minimum number of
moves required to make the grid optimal.

#{b.samples '''
2

****
*.*.
.**.
*..*

*.*.
.***
*.**
.**.
''', '''
Case 1: 4
Case 2: 1
'''}

## Explanation of Sample Cases ##

For the first case, moving two coins from the top row into the second row,
one in the third row and one in the fourth row can turn the grid into
the following:

~~~
.**.
****
..**
*.*.
~~~

Which has 16 even lines. For the second case, just one move is necessary to
turn it into an optimal grid (the question of *which* move is left as an
exercise).

"""
# |end.markdown|
