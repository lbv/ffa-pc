doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem C: The Courier Problem

Here is a pretty problem which has been the source of much confusion in the
past due to unfortunate misunderstandings while defining its terms.

#{b.figureRight 'The courier galloping around the army', 'courier.jpg', 0.4, 11}

The ancient version which appears in old mathematical works goes something
like this: A courier starting from the rear of a moving army, fifty miles
long, dashes forward and delivers a dispatch to the front and returns to his
position in the rear, during the exact time it required the entire army to
advance just fifty miles. How far did the courier have to travel in
delivering the dispatch, and returning to the rear of the army?

- - -

Now, for the general problem: Consider an army $L$ miles long, marching
forward at constant speed. A courier starts from the rear of the army,
travels all the way to the front, and immediately goes back to the rear of
the army, reaching his final destination at the precise moment when the army
has covered a distance of exactly $L$ miles. Assume that the courier also
moves with constant speed, and that the time he spends on the front
delivering the dispatch is negligible.

Write a program that, given the value $L$, calculates the total distance
traveled by the courier, in miles.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case is described by a single integer $L$, in its own line.

#{b.constraints 'T \\leq 3000', '1 \\leq L \\leq 10^5'}

## Output ##

For each test case, print the case number, followed by the total distance
covered by the courier. Print this result as a real number, with exactly two
digits after the decimal point.

#{b.samples '''
1
50
''', '''
Case 1: 120.71
'''}
"""
# |end.markdown|
