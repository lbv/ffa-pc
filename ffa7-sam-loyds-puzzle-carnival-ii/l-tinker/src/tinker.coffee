doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem L: The Tinker's Puzzle

#{b.figureRight 'Tell the size of the kettle', 'tinker.jpg', 0.38, 11}

There is an old nursery rhyme that says:

> I agreed with a tinker whose name was Doo-little\\
> to make for my aunt a flat-bottomed kettle.
>
> Twelve inches exactly the depth of the same,\\
> and twenty-five gallons of beer to contain.
>
> The inches across at the top would show\\
> just twice the width, as measured below.
>
> So tell me that width, across at the top\\
> for auntie now wants a lid from the shop.

Can you indicate the diameter of the required lid to fit on the kettle,
which is twelve inches deep, and will hold just twenty-five gallons?

- - -

Given the depth of the kettle, and the volume it can hold, calculate its
diameter at the top---which is twice the diameter at the bottom. The depth
is given in inches, while the volume is given in "beer gallons", which you
should assume to be equivalent to 282 cubic inches.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

Each test case contains two integers: $D$ and $V$ which denote the depth and
the volume of the kettle, respectively.

#{b.constraints 'T \\leq 1000', '1 \\leq D \\leq 50', '1 \\leq V \\leq 100'}

## Output ##

For each test case, print the case number, followed by the diameter at the
top of the kettle, in inches. Print this as a real number rounded to exactly
three digits after the decimal point.

#{b.samples '''
2
12 25
10 33
''', '''
Case 1: 35.810
Case 2: 45.069
'''}
"""
# |end.markdown|
