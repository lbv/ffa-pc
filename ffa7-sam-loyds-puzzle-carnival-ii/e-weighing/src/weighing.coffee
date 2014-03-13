doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem E: Outwitting the Weighing Machine

#{b.figureRight 'Guess the weights of the girls', 'weighing.jpg', 0.4}

Some school children discovered that by getting on a weighing
machine in couples, and then exchanging places---one at a time---they could
get the correct weight of a whole party on the payment of but one cent. They
found that in couples they weighed (in pounds): 129, 125, 124, 123, 122,
121, 120, 118, 116 and 114. What was the weight of each one of the five
little girls if taken separately?

It proves that they must have been clever scholars or they never would have
been able to work out the correct answer to such an interesting puzzle
question, which is liable to confuse older heads than theirs.

- - -

Given a list of 10 integers, representing the weighs of each couple formed
from a group of 5 people, determine the weights of each person.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case is described by 10 integers $W_1, W_2, \\ldots, W_{10}$ in a
single line.

#{b.constraints 'T \\leq 3000',
'100 \\leq W_1 \\leq W_2 \\leq \\ldots \\leq W_{10} \\leq 400'}

## Output ##

For each test case, print the case number, followed by the 5 weights asked,
separated by spaces. Print these numbers in ascending order.

#{b.samples '''
3
114 116 118 120 121 122 123 124 125 129
110 111 114 115 118 118 119 122 123 126
180 190 190 196 196 206 216 216 226 232
''', '''
Case 1: 56 58 60 64 65
Case 2: 53 57 58 61 65
Case 3: 90 90 100 106 126
'''}
"""
# |end.markdown|
