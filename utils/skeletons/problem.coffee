doc = require 'phi.pc/doc'


b = new doc.DocBuilder

# |begin.markdown|
b.build """
% Problem X:

#{b.figureRight 'title', '.jpg', 0.33}

Foo

- - -

Foo

## Input ##

Input starts with a positive integer **T**, that denotes the number of test
cases.

#{b.constraints 'T \\leq 100'}

## Output ##

For each test case, print the case number, followed by

#{b.samples '''
''', '''
'''}
"""
# |end.markdown|
