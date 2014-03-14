doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem M: The Miser's Puzzle

#{b.figureRight 'Tell how much the miser has', 'miser.jpg', 0.3, 14}

There once was an old miser who had hoarded up a quantity of five, ten and
twenty-dollar gold pieces. Before starving to death, the miser used to count
his gold using a peculiar method. He used to take his coins and form 4
piles with them, such that each pile had the same amount of 5, 10 and
20-dollar pieces. Not only that, but he could also divide his gold into 5
groups, also alike (with the same number of coins of each type). Finally he
repeated the process, this time splitting the gold into 6 alike groups.

Assuming that each of the piles he made had a positive number of gold pieces
of each type, what is the minimum amount of gold that the miser had?

- - -

Let's say that the miser was able to divide his gold in $N$ different ways,
and for each method of partitioning he was able to form $M_i$ groups (for $1
\\leq i \\leq N$). You are asked now to determine the minimum amount of gold
the miser had.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each case starts with an integer $N$ in a single line. The next line
contains $N$ integers, representing the set $M_1, M_2, \\ldots, M_N$.

#{b.constraints 'T \\leq 2000', '1 \\leq N \\leq 8',
'2 \\leq M_1 < M_2 < M_3 < \\ldots < M_N \\leq 100'}

## Output ##

For each test case, print the case number, followed by the the minimum
amount of gold that the miser could have.

#{b.samples '''
2
3
4 5 6
4
10 14 15 35
''', '''
Case 1: 2100
Case 2: 7350
'''}
"""
# |end.markdown|
