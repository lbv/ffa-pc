doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem G: A Daisy Puzzle Game

#{b.figureRight 'Little Gretchen playing the Daisy game', 'daisy.jpg', 0.33, 11}

Gretchen, a little peasant girl from the Swiss Alps, is an expert at the
Daisy game, a simple game that is very well-known around the country. Two
players pluck off the petals of a Daisy flower, and each player is always at
liberty to pluck a single petal or any two contiguous ones, so that the game
would continue by singles or doubles until the victorious one takes the last
leaf and leaves the "stump"---called the "old maid"---to the opponent.

The pretty mädchen has mastered the Daisy game to such an extent that she
always plays *optimally*. In other words, she always plays by performing the
best possible moves on each turn, a feat which never fails to astonish
tourists who dare to challenge her to a game.

Analyzing the game, it is not very complicated to figure out a winning
strategy for the second player, as long as the game starts with a complete
flower (having all of its petals intact). However, what will happen when
Gretchen plays against an opponent that also plays optimally, and some of
the flower's petals have been plucked off at random?

- - -

A flower is described by a number $N$ which represents the original number
of petals of the flower, and a list of the petals that have been plucked
off. All petals are numbered from $1$ to $N$, and given the circular nature
of the flower, that means petals $1$ and $N$ are originally adjacent.

Given the description of a flower, and assuming it's Gretchen's turn, will
she win the game? Remember that both players always play optimally.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case begins with two integers in a single line, $N$ and $M$,
representing the number of petals originally in the flower, and the number
of petals that have been plucked off, respectively.

The next line contains $M$ distinct integers, representing the petals that
have been plucked off. These numbers will always be in ascending order.

#{b.constraints 'T \\leq 1000', '3 \\leq N \\leq 20', '1 \\leq M < N'}

## Output ##

For each test case, print the case number, followed by the string **yes** if
Gretchen wins the game, or **no** otherwise.

#{b.samples '''
2
13 1
7
5 3
1 3 4
''', '''
Case 1: yes
Case 2: no
'''}
"""
# |end.markdown|
