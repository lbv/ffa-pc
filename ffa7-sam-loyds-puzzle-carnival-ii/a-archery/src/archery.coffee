doc = require 'phi.pc/doc'


b = new doc.DocBuilder


# |begin.markdown|
b.build """
% Problem A: The Archery Puzzle

#{b.figureRight 'The young archer scored 100 points', 'archery.jpg', 0.4, 8}

Here is an odd little puzzle which occurred the other day at an archery
meeting. The young lady who carried off the first prize scored exactly one
hundred points. Can you figure out how many arrows she used, as well as the
points awarded to each arrow?

- - -

You participate in an archery competition, and are interested in how to
score some fixed amount of points.

You will receive a list of $N$ positive integers, $P_1, P_2, \\ldots, P_N$,
which represent the scores in the archery target; that is, the different
scores that can be achieved with a single hit. You will also receive an
integer $S$, which is the total score you want to obtain.

Determine the minimum number of arrows necessary to score $S$ points, and
print the points awarded to each of those arrows, sorted in descending
order. If there is more than one group of arrows that provide a valid
solution, choose the solution for which the first arrow scores the highest
amount of points; if the solution is still not unique, then choose one in
which the second arrow scores the highest score possible, and keep applying
this reasoning for the rest of the arrows.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case starts with two integers in a single line: $N$ and $S$. The
second line for each test case contains $N$ integers in ascending order:
$P_1, P_2, \\ldots, P_N$.

#{b.constraints 'T \\leq 500', '1 \\le N \\le 50',
'1 \\le P_1 < P_2 < P_3 < \\ldots < P_N \\le S \\le 300'}

## Output ##

For each test case, print the case number, followed by the minimum number of
arrows required to score $S$ points between square brackets, and then the
sequence of points for each arrow, in descending order. These scores must be
separated by single spaces.

If the test case does not have a solution, simply print the case number,
followed by the string **impossible**.

#{b.samples '''
3
6 100
16 17 23 24 39 40
3 50
10 15 20
2 25
7 13
''', '''
Case 1: [6] 17 17 17 17 16 16
Case 2: [3] 20 20 10
Case 3: impossible
'''}
"""
# |end.markdown|
