doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem I: In Puzzleland (IV)

#{b.figureRight "To the right: London tower's clock", 'puzzleland4.jpg', 0.35, 10}

While Whittington is busy with his cat, the small boy asks the
princess: if it takes six seconds for the clock to strike six, how long
would it take to strike twelve?

- - -

Every hour the tower clock sounds a large bell as many times as the number
of hours it is marking. So, for example, at 6 o'clock it sounds the bell six
times. The time it takes to complete this task is counted from the moment it
hits the bell the first time until the moment it hits it the last time. The
time between consecutive strikes is always constant.

You know that at hour $H_1$ it takes the clock exactly $S$ seconds to strike
$H_1$. How long would it take to strike a different hour $H_2$?

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case is described by three integer numbers in a single line, in
order: $H_1, S, H_2$.

#{b.constraints 'T \\leq 5000', '2 \\leq H_1, H_2 \\leq 12', '0 < S < 60',
'H_1 \\ne H_2'}

## Output ##

For each test case, print the case number, followed by the exact number of
seconds that the clock takes to mark $H_2$.

If this number is not an integer, and is less than $1$, then print it as a
simplified fraction `p/q` (that is, $p$ and $q$ have to be coprimes).

If the answer is not an integer, and is greater than $1$, then print it as a
mixed number. See the samples below for more details.

#{b.samples '''
3
6 6 12
6 6 11
3 1 2
''', '''
Case 1: 13 1/5
Case 2: 12
Case 3: 1/2
'''}
"""
# |end.markdown|
