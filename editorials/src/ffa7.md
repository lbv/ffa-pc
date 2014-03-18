Free for All 7 came and went. It got little attention and few participants,
so I won't include any statistics on participation here.

Nevertheless, thanks to anyone who gave it a try.

- - -

### A - The Archery Puzzle  ###
*Sample solution (BFS)*: [`archery-bfs.cpp`][a1] --- *Alternative solution
(DP)*: [`archery.cpp`][a2]

A relatively simple problem that can be solved in different ways. The most
straightforward---and possibly most efficient as well---is, I think, using a
*breadth-first search*. It just needs a little care in the implementation,
so the solution ends up in the right order (the highest scores take
precedence over the lowest scores every time a new state is visited).

[a1]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/a-archery/prg/archery-bfs.cpp
[a2]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/a-archery/prg/archery.cpp

### B - In Puzzleland (III) ###
*Sample solution*: [`puzzleland3.cpp`][b]

This problem is basically asking for the [Hamiltonian path][ham] of a graph.
Since the maximum number of nodes is small (15), it can be tackled with
dynamic programming, with a complexity of *O(2^N+1^)*.

By the way, if you're wondering why the name for this problem has (III) at
the end, see [FFA5][ffa5].

[b]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/b-puzzleland3/prg/puzzleland3.cpp
[ffa5]: https://sites.google.com/a/diptongonante.com/ffa-pc/contests/free-for-all-5-sam-loyd-s-puzzle-carnival
[ham]: http://en.wikipedia.org/wiki/Hamiltonian_path


### C - The Courier Problem ###
*Sample solution*: [`courier.cpp`][c]

This one I consider to be a great example of a good, short algebraic puzzle.
There are probably many different ways in which a satisfactory solution can
be reached, but here's one:

Let us first consider two separate phases: the first one, in which the
courier travels all the way to the front of the army, and the second one, in
which he travels back to the rear. Now, one strategy that can be used to
formulate the necessary mathematical relations to solve this is by
similarity. The following statement captures this idea in words (I'll
replace the courier with letter *C* and the army with letter *A*):

> The distance traveled by **C** during phase 1 is to the distance
> traveled by **A** during that same phase, as the distance traveled by
> **C** during phase 2 is to the distance covered by **A** in phase 2.

Hopefully this already suggests the road that will be taken to reach the
answer. Now, to put it in mathematical terms, let's call *d* the distance
traveled by the army during phase 1. Then it should not be difficult to see
how the previous statement in words translates into the following:

<div style="display:block;text-align:left"><img
src="http://mathurl.com/nccmj9r.png" border="0"></div>

From which the value of *d* can be deduced. The final answer is *L + 2d*
(the courier has to move *L + d* miles in phase 1, and *d* miles in phase
2).

[c]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/c-courier/prg/courier.cpp

### D - Disputed Claims ###
*Sample solution*: [`disputed.cpp`][d]

Sam Loyd showed great interest in [Pythagorean triples][pyt] when creating
puzzles.

Basically a single pre-processing step to calculate all necessary triples
(using a method like Euclid's) is all that is required to solve this
problem. Then each test case can be answered in *O(log N)*---if, for
example, the triples are stored in something like a hash-map where searching
over the keys is done with binary search. For more details, see the notes
for problem F in [FFA5][ffa5].

[d]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/d-disputed/prg/disputed.cpp
[pyt]: http://en.wikipedia.org/wiki/Pythagorean_triple

### E - Outwitting the Weighing Machine ###
*Sample solution*: [`weighing.cpp`][e]

I really like this problem. It is one of those puzzles that can appear to be
easy at first, and yet they can end up creating much confusion while working
out the answer. I'm sure there are many ways to produce the answer, but
here's the one I personally used:

Let us start by defining *G~1~, G~2~, ... , G~5~* to be the weights of the
girls in order, with *G~1~* being the lowest weight, and *G~5~* the highest
weight. Now, a couple of useful observations: *W~1~* must be equal to *G~1~ +
G~2~*. Similarly *W~10~* has to be *G~4~ + G~5~*. You can even go one
further, and be confident that *W~2~ = G~1~ + G~3~* and *W~9~ = G~3~
+ G~5~* (make sure to convince yourself of this, if you need to). The second
observation is that each girl ends up being weighed 4 times, which
means that, if we call *S* the total sum of weights of all the girls, then
we can deduce its value from:

<div style="display:block;text-align:left"><img
src="http://mathurl.com/ovpenv8.png" border="0"></div>

Now we can deduce all the weights systematically. For example, starting with
the girl in the middle: *G~3~ = S - W~1~ - W~10~*. Then we can obtain *G~1~*
from: *G~1~ = W~2~ - G~3~*. Something similar goes for *G~5~*. And then
*G~2~* and *G~4~* can be deduced from *G~1~, W~1~, G~5~, W~10~*.

[e]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/e-weighing/prg/weighing.cpp

### F - The Jolly Friar's Puzzle ###
*Sample solution*: [`friar.cpp`][f]

This problem is kind of *ad-hoc*. The main difficulty is that it needs a
fair amount of legwork to deal with analyzing and manipulating 4-by-4
boards. One way to do it is using bitwise manipulations, which simplifies
the calculations.

A good idea is to start by precomputing all optimal grids, which, it turns
out, are just 4 (and are rotations of the same configuration). Then for each
test case calculate the minimum number of moves to transform it into each of
the optimal grids and just use the lowest number. A similar idea (but on a
harder general problem) can be applied in LightOJ's problem *N Queen Again*
(ID 1061).

[f]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/f-friar/prg/friar.cpp


### G - A Daisy Puzzle Game ###
*Sample solution*: [`daisy.cpp`][g]

A fairly straightforward impartial game puzzle. It can be solved using the
Sprague-Grungy theorem, as is usual in these cases. For more reference
material, see the notes for problem C in the editorial for [FFA5][ffa5]
(including the link to the Treblecross problem).

[g]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/g-daisy/prg/daisy.cpp

### H - Who Will Get the Nomination? ###
*Sample solution*: [`nomination.cpp`][h]

This is (from my point of view) possibly the hardest problem of this
contest. It can be solved using [IDA*][ida], which is something that is not
very frequently seen in programming contests. It is, however, a very useful
technique for finding solutions in problems where a reasonable heuristic
can be formulated.

The nice thing is that, if your heuristic method is reasonably good (if the
estimation is not *too* far off), and it can be computed quickly, then it
can easily reach a solution surprisingly quickly in situations where using
other algorithms (e.g. BFS/DFS) would be completely unfeasible.

[h]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/h-nomination/prg/nomination.cpp
[ida]: http://en.wikipedia.org/wiki/IDA*

### I - In Puzzleland (IV) ###
*Sample solution*: [`puzzleland4.cpp`][i]

This is one of the easiest problems in the contest, although it wasn't tried
by anyone. Some very basic algebra is all that is needed here---well, that
and formatting the output correctly.

[i]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/i-puzzleland4/prg/puzzleland4.cpp

### J - Mother's Jam Puzzle ###
*Sample solution*: [`jam.cpp`][j]

There *may* be may ways to solve it, but the most straightforward for me was
using Gaussian elimination over a matrix.

[j]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/j-jam/prg/jam.cpp

### K - Skating Puzzle ###
*Sample solution*: [`skating.cpp`][k]

Another simple algebraic problem, which all participants actually tried and
successfully solved. Nothing specially interest to note here, I think.

[k]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/k-skating/prg/skating.cpp

### L - The Tinker's Puzzle ###
*Sample solution*: [`tinker.cpp`][l]

A straightforward geometric problem. The most natural way to solve it for me
was simply applying a little calculus, using integration to find the volume
of what is called a *solid of revolution*.

If we call *r* the radius of the bottom of the kettle, then we can imagine
the kettle as a solid of revolution by imaging a straight line from *(0, r)*
to *(D, 2r)*, and then rotating this line around the *X* axis. This leads to
the following expression:

<div style="display:block;text-align:left"><img
src="http://mathurl.com/nwa3qo6.png" border="0"></div>

After a little math gymnastics, the expression for *r* can be found to be:

<div style="display:block;text-align:left"><img
src="http://mathurl.com/lqv2okw.png" border="0"></div>

From which the final answer results as *4r*.

[l]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/l-tinker/prg/tinker.cpp

### M - The Miser's Puzzle ###
*Sample solution*: [`miser.cpp`][m]

It should not be too hard to notice that this problem is basically asking
for the *lowest common multiple* of the set of numbers given in the input.
Finding this LCM, and then multiplying it by *5 + 10 + 20* (the values of
the gold pieces) produces the final answer.

[m]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/m-miser/prg/miser.cpp


### N - The Pony Cart Problem ###
*Sample solution*: [`pony.cpp`][n]

Another (perhaps simpler) geometric problem. The hardest part is formulating
the relation that helps us find the radius of the largest circle. One
possible relation can be formulated like this. Let *r* be the radius of the
smaller circle (made by the inner wheels). Then *N* times the circumference
of a circle of radius *r* has to be equal to the circumference of the circle
of radius *r + D*:

<div style="display:block;text-align:left"><img
src="http://mathurl.com/qfvhtmg.png" border="0"></div>

From which *r* can be deduced, and then the final answer is:

<div style="display:block;text-align:left"><img
src="http://mathurl.com/pkzvubl.png" border="0"></div>

Unfortunately, I made a gross mistake when preparing the contest, and the
samples in the problem statement, the solution and data sets were wrong, so
I guess that's why nobody tried this. My fault, sorry.

[n]: https://github.com/lbv/ffa-pc/blob/master/ffa7-sam-loyds-puzzle-carnival-ii/n-pony/prg/pony.cpp

- - -

It was fun preparing this contest. I still have notes on enough problems
from Sam Loyd's Cyclopedia to create at least two more contests of this
kind, but I think it will take me some time to come up with Puzzle Carnival
III. In the meantime, I may create a few other contests with all kinds of
problems. By the way, if you're interested in helping with this and maybe
contributing a problem or two, feel free to let me know!

Until next time.
