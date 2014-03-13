doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem D: Disputed Claims

#{b.figureRight 'The miners and their claims', 'disputed.jpg', 0.33, 11}

Our puzzle shows an animated dispute between some miners over their
respective claims. It seems that they have obtained "patents" on some mining
claims of the same size. Each claim was in the form of a right angled
triangle, and all of exactly the same area, but of different dimensions, as
would be the case with a triangle with a base of 35 feet, an elevation of 12
and the hypothenuse of 37, as compared with another with dimensions of 20,
21 and 29, as both contain areas of 210 feet.

The puzzle calls for the complete list of different triangles with an area
of 210 square feet, taking into account that all triangles must have a
square angle, and the lengths of their sides must be integers.

- - -

Your task now is to identify all possible triangles (right-angled and with
sides of integer lengths, as in the puzzle) with a certain area $A$. Print
the lengths of each triangle in ascending order, and the whole list of
triangles in ascending order as well---sort the triangles first by their
first (shortest) side, then the second side and finally by their longest
side.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test is described by a single integer $A$, in a line of its own.

#{b.constraints 'T \\leq 10^4', '1 \\leq A \\leq 10^7'}

## Output ##

For each test case, print the case number, followed by the number of valid
triangles with area $A$. Then print the sorted list of these triangles, one
per line, using the format `(a,b,c)`, where $a, b, c$ are the lengths of the
sides of the triangle, in ascending order.

#{b.samples '''
4
210
1000
2400
3360
''', '''
Case 1: 2
(12,35,37)
(20,21,29)
Case 2: 0
Case 3: 1
(60,80,100)
Case 4: 3
(30,224,226)
(48,140,148)
(80,84,116)
'''}
"""
# |end.markdown|
