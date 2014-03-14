doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem K: Skating Puzzle

#{b.figureRight 'Jennie and Maude skating', 'skating.jpg', 0.38, 8}

Two graceful skaters, Jennie and Maude, race each other along a track one
mile long. However, they start from opposite ends of the track, and skate
towards the other's starting point. Because of a strong wind, Jennie
receives an important advantage that helps her finish the race two and a
half times as quick as Maude. Maude finished the race six minutes later.
What was the time of each of them skating the mile?

- - -

Assume that the race always happens in a track one mile long, and that the
skaters always maintain constant speeds. Let $v_J$ be Jennie's speed, and
$v_M$ Maude's speed. We will call $r$ the ratio between the two speeds---that
is, $r=v_J \\div v_M$. Let $t$ be the time in minutes between the moment when
Jennie finished the race and the moment when Maude did the same. Given the
values $r$ and $t$, determine the time that each skater took to complete the
race.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case contains two real numbers: $r$ and $t$, as described
above. Each number will be presented with two digits after the decimal
point.

#{b.constraints 'T \\leq 5000', '1 < r \\leq 10', '0 < t \\leq 30'}

## Output ##

For each test case, print the case number, followed by two real numbers: the
time in minutes of Jennie and Maude to complete the race, in that order.
Print these numbers with exactly three digits after the decimal point.

#{b.samples '''
2
2.50 6.00
1.88 3.33
''', '''
Case 1: 4.000 10.000
Case 2: 3.784 7.114
'''}
"""
# |end.markdown|
