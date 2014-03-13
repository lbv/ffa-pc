doc = require 'phi.pc/doc'


b = new doc.DocBuilder


# |begin.markdown|
b.build """
% Problem B: In Puzzleland (III)

#{b.figureRight "Whittington's cat is very well trained", 'puzzleland3.jpg', 0.5, 14}

Whittington is showing his trained cat in its surprising feat of going from
A to Z, grabbing all the mice in his way while stepping on each circle just
once.

- - -

You receive an arbitrary, undirected graph, where each node is identified by
a single uppercase letter. Two vertices are marked as endpoints; one is the
*source*, or starting point, and the other is the *target*, or end point.

Your job is to imitate the cat's ability, and identify a path that goes from
the source to the target, visiting each node in the graph exactly once.  If
there is more than one valid path, choose the lexicographically lowest one.

## Input ##

Input starts with a positive integer $T$, that denotes the number of test
cases.

There's a blank line at the start of each case. Then two integers are given
in a single line: $N$ and $M$, representing the number of nodes and the
number of bi-directional edges in the graph, respectively.  You can assume
that there is at most one edge between any pair of nodes, and that each edge
will be reported only once.

The next line will contain $N$ distinct letters, separated by spaces, which
are the identifiers for all the nodes in the graph. The first letter in this
list will be the *source*, the last letter will be the *target*. All letters
will be uppercase letters from the English alphabet.

Then $M$ lines will be presented, describing the edges of the graph. Each of
these lines contain two distinct letters, which describe two nodes that are
connected by an edge.

#{b.constraints 'T \\leq 60', '2 \\le N \\le 15'}

## Output ##

For each test case, print the case number, followed by the sequence of
letters that describe the path from the source to the target, visiting all
nodes exactly once.

If a valid solution doesn't exist, print the word **impossible**.

#{b.samples '''
3

12 14
A B C D E F U V W X Y Z
A F
A V
B U
B W
C D
C V
D Y
D W
E X
E Z
F U
F Y
U Z
W X

3 2
A B C
A B
A C

4 5
L N I K
L N
I L
I N
K N
K I
''', '''
Case 1: AVCDYFUBWXEZ
Case 2: impossible
Case 3: LINK
'''}
"""
# |end.markdown|
