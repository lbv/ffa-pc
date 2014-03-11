A total of 41 participants joined this contest. I think this has been the
most successful FFA contest in this regard. Thanks to everyone who joined in
and helped spreading the word, particularly to S. M. Ijaz-ul-Amin Chowdhury.

Congratulations to Rashedul Hasan Rijul from Bangladesh for solving the
entire problem set, and finishing in first place.

- - -

### A - Achilles Paradox ###
*Tried by 33 participants*.
*Number of ACs: 30*.
*Sample solution*:
[`paradox.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/a-paradox/code/paradox.cpp)

This is a relatively simple math problem. It can be solved with a method
similar to the one explained for the problem "The Leaning Tower of Pisa" in
[FFA5](https://sites.google.com/a/diptongonante.com/ffa-pc/contests/free-for-all-5-sam-loyd-s-puzzle-carnival/editorial-sam-loyd-s-puzzle-carnival).
However, there is an even simpler way to come up with the answer using
standard kinematics equations.

Note that you can make your calculations entirely with integers (avoiding
floating point operations).

### B - The Beauty Salon ###
*Tried by 25 participants*.
*Number of ACs: 23*.
*Sample solution*:
[`salon.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/b-salon/code/salon.cpp)

A nice little problem that can be tackled with a simple simulation. Take the
characters one by one and decide what happens at each step.

### C - Playlist Order ###
*Tried by 12 participants*.
*Number of ACs: 9*.
*Sample solution*:
[`order.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/c-order/code/order.cpp)

I remember having solved a problem very similar to this one in a real--life
competition a while ago with my team. I simply spent a little while looking
at the samples from the problem statement until the light bulb went on in my
head. That's a nice feeling, isn't it?

Go through the inversion table backwards, starting with the last element. If
you think about it, it should be clear that the last item **must** be zero,
otherwise the list is invalid. Keep applying a similar reason to the
following elements. At the same time, you can be build the permutation using
the numbers from the inversion table (again, going backwards).

### D - All Roads Lead to Thessaly ###
*Tried by 9 participants*.
*Number of ACs: 9*.
*Sample solution*:
[`roads.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/d-roads/code/roads.cpp)

I hope the problem statement was clear enough in suggesting that this should
be solved using a Minimum Spanning Tree. However, it needs also an
additional Depth First Search mechanism to retrieve the lists of cities that
have to be visited in a given path.

In case you're interested in this kind of thing, note that the property
implied by the Tortoise when he tells Achilles that there should not be a
problem if all the roads have distinct lengths (that is, there is only one
unique MST in that case) can be easily proven using a method very similar to
the one used in the [proof of
correctness](http://en.wikipedia.org/wiki/Kruskal%27s_algorithm#Proof_of_correctness)
for Kruskal's algorithm.

### E - Counting Primes ###
*Tried by 10 participants*.
*Number of ACs: 5*.
*Sample solution*:
[`counting.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/e-counting/code/counting.cpp)

This problem is kind of straightforward in the sense that it just requires a
pre--calculation of all primes up to 10^6^, and the use of a data structure
that can handle the queries with a complexity of at most *O(log N)*. A
segment tree, for example. If you have not used this type of data structure
before, look into it... it's pretty useful stuff.

### F - Identifying Comments ###
*Tried by 6 participants*.
*Number of ACs: 4*.
*Sample solution*:
[`comments.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/f-comments/code/comments.cpp)

This problem requires the parsing of C--style comments, which is something
very useful if you ever need to write some piece of software that requires
processing text. Just implement a little parser for it... nothing too fancy.
You should focus mostly in the lexical analyzer, which must skip over
literals, strings and whitespace, and increase the counters whenever it
processes comments.

### G - Strange Calculator ###
*Tried by 15 participants*.
*Number of ACs: 12*.

Wanna hear something embarrassing? This problem helped reveal an outstanding
bug in the Big Integer code I've been using for quite a while in C++. The
subtraction operator was implemented incorrectly. This is why during the
contest so many people kept making submissions for this problem and
receiving WA. When I noticed, it was clear that something fishy had to be
going on, so I went and checked and sure enough... a bug in my code.

I included this problem in the contest with the intention of encouraging
people into obtaining proper Big Int implementations or writing their own. I
guess it was successful in that sense, because at the very least I had to fix
my own code :).

I don't include a sample solution for this problem because I lost most of
the files from the contest in another embarrassing mistake on my part, and
this is the only problem for which I could not recover the source code.
Sorry.

Some participants did the easy thing, and just solved this problem in Java,
which is completely valid, of course, so that's always an option.

### H - Almost Magic Squares ###
*Tried by 5 participants*.
*Number of ACs: 2*.
*Sample solution*:
[`squares.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/h-squares/code/squares.cpp)

This is one of my favourite problems from this contest. As you can see from
the [contest
data](https://sites.google.com/a/diptongonante.com/ffa-pc/contests/free-for-all-6/free-for-all-6---conte)
page, this was based in an old problem used in an ACM regional contest, and
when I read it I knew I wanted to use it for my contest right away.

The main observation I can point out is this: the fact that the modified
numbers are increased by powers of two is not casual. If you are familiar
with binary representations and bitwise operators, it should be clear that,
given the value **X** of the almost--magic square, and the sum from a row or
column that is *different* from **X**, you can easily determine which
number was altered; if the difference is 2^0^, then S~1~ is in that
row/column, if the difference is 2^1^, then S~2~ is there, and so on.

### I - A Safe Polynomial ###
*Tried by 6 participants*.
*Number of ACs: 6*.
*Sample solution*:
[`polynomial.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/i-polynomial/code/polynomial.cpp)

This is basically a brute--force problem. Just be careful in the order you
seek for the solution, so it's the lexicographically greatest.

### J - Delivering Mail ###
*Tried by 7 participants*.
*Number of ACs: 7*.
*Sample solution*:
[`mail.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/j-mail/code/mail.cpp)

This is meant to be solved with a simple *O(N)* algorithm that calculates the
prefix sums of the two lists. Calculate the cumulative sums from
left--to--right in the first list, and right--to--left in the second list,
and then look if for some index *i*, the sums at A~i~ and T~i+1~ are equal.

### K - Supermarket Promo ###
*Tried by 10 participants*.
*Number of ACs: 8*.
*Sample solution*:
[`promo.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/k-promo/code/promo.cpp)

A basic dynamic programming problem. If you couldn't recognise it during the
contest, look into the *Longest Increasing Subsequence* problem. However,
notice that this particular instance doesn't ask for the length of the
subsequence, but for the maximum possible sum among all LIS. It can be
solved with a *O(n^2)* algorithm.

### L - Hilbert's Puzzle ###
*Tried by 6 participants*.
*Number of ACs: 6*.
*Sample solution*:
[`hilbert.cpp`](https://github.com/lbv/ffa-pc/blob/master/ffa6-achilles-and-the-tortoise/l-hilbert/code/hilbert.cpp)

There's another curious story behind this problem. I actually had an
entirely different problem in mind. I wanted to include a slight variation
of this problem: [Hilbert Curve
Intersections](http://contests.vanb.org/2003regionals/8-24/problems/hilbert/hilbert.html).
I suggest you at least take a look at it... it's a fantastic problem.

Anyway, the contest was about to start and I had this problem practically
ready, but when I generated the PDFs, I noticed that this problem in
particular was coming up completely messed up because of technical issues
and the fact that I included two figures in it. I figured that fixing the
issues would take me a while, and since I was a little
sleep--deprived at that point, and the contest was about to start, I decided
to simply discard my original plan and came up with the alternative puzzle
that you can see in the final contest. Not nearly as interesting as the
original puzzle, but well...

Solving it should not be too hard. Consider the way successive orders of the
curve are built and you can see that a factor of 4 is somehow involved.
However, there's another interesting little detail, related to the way the
pieces are connected with lines in the last step of the process described in
the problem statement. Take a look at the graphs for the first few orders of
**H** and it should be clear what's going on.

- - -

Again, thank you all for your interest in these little contests. This is
going to be the last contest for this year, so my best wishes to all and a
happy new year. See you in 2013, with Free For All 7 :).
