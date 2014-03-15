doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem N: The Pony Cart Problem

#{b.figureRight 'What is the circumference of the outer track?', 'pony.jpg', 0.4}

While driving a speedy pony, a young boy went around a sharp turn at a gait
which threatened an upset to the pony cart, as well as to his father's
nerves. Fortunately no accidents occurred, and after some experimentation,
the following information was gathered:

In turning the pony cart around within a ring of a certain diameter, which
might be said to be reasonably safe, it was found that the outer wheels made
two turns to the inner wheels one; the wheels were fixed at the statutory
distance of five feet apart on the axletree. The problem is to guess the
circumference of the track described by the outer wheels in making the turn.

- - -

Assume that the tracks marked on the floor are perfectly circular, that the
distance between a wheel on one side and its opposite on the other side is
$D$ feet, and that for one turn of the inner wheels, the outer wheels make
$N$ turns. Determine the circumference of the circle formed by the outer
wheels.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case is described by the two real numbers $D$ and $N$ in the same
line. These numbers are always given with two digits after the decimal
point.

#{b.constraints 'T \\leq 1000', '3 \\leq D \\leq 10', '1 < N \\leq 10'}

## Output ##

For each test case, print the case number, followed by the circumference of
the outer tracks (in feet), with exactly three digits after the decimal
point.

#{b.samples '''
3
5.00 2.00
4.20 1.44
8.03 2.01
''', '''
Case 1: 62.832
Case 2: 119.952
Case 3: 99.909
'''}
"""
# |end.markdown|
