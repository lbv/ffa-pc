doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem J: Mother's Jam Puzzle

#{b.figureRight "Mrs. Hubbard's kids inspect the jam", 'jam.jpg', 0.33, 10}

Mrs. Hubbard has invented a clever system for keeping tabs on her blackberry
jam. She filled twenty-five jars and arranged the three sizes so as to have
twenty quarts on each shelf. Can you guess her secret so as to tell how much
jam is on each type of jar?

- - -

As you can see, there are three types of jars, which we will call *small*,
*medium* and *large*. Mrs. Hubbard puts a certain number of jars on each of
her three shelves. If all jars are completely filled with jam, and you know
the total amount of jam in each shelf, determine the capacity of each type
of jar.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case begins with a blank line; after that, there will be three
lines describing each shelf.

A shelf is described by four numbers, in order: three integers $S, M, L$
which represent the number of small, medium and large jars in the shelf, and
a real number $J$ that represents the total amount of jam for that shelf.

The value of $J$ will always be presented with two digits after the decimal
point. You may assume that all test cases have a valid answer.

#{b.constraints 'T \\leq 5000', '0 \\le S, M, L \\le 15', '0 < J \\le 100'}

## Output ##

For each test case, print the case number, followed by the capacity of the
small, medium and large jars, in that order. Print the answers as real
numbers rounded to exactly two digits after the decimal point.

#{b.samples '''
2

3 3 1 20.00
6 0 2 20.00
6 4 0 20.00

3 0 1 6.00
0 2 2 10.00
1 3 1 10.00
''', '''
Case 1: 1.11 3.33 6.67
Case 2: 1.00 2.00 3.00
'''}
"""
# |end.markdown|
