# Algorithm - Coursera

## Big-O

### Definitions

Consider two functions $f(n)$ and $g(n)$ that are defined for all positive integers and take on non-negative real values. (Some frequently used functions used in algorithm design: $\log n$, $\sqrt{n}$, $n\log n$, $n^3$, $2^n$). We say that **$f$ grows slower than $g$** and write $f \prec g$, if $\frac{f(n)}{g(n)}$ goes to 0 as $n$ grows. We say that **$f$ grows no faster than $g$** and write $f \preceq g$, if there exists a constant $c$ such that $f(n) \le c \cdot g(n)$ for all $n$.  

Three important remarks.
1. $f \prec g$ is the same as $f=o(g)$ (small-o) and $f \preceq g$ is the same as $f=O(g)$ (big-O). In this notebook, we've decided to stick to the $\preceq$ notation, since many learners find this notation more intuitive. One source of confusion is the following: many learners are confused by the statement like "$5n^2=O(n^3)$". When seeing such a statement, they claim: "But this is wrong! In fact, $5n^2=O(n^2)$!" At the same time, ==both these statements are true:== $5n^2=O(n^3)$ and also $5n^2=O(n^2)$. They both just say that $5n^2$ grows no faster than both $n^2$ and $n^3$. In fact, $5n^2$ grows no faster than $n^2$ and grows slower than $n^3$. In $\preceq$ notation, this is expressed as follows: $5n^2 \preceq n^2$ and $5n^2 \preceq n^3$. This resembles comparing integers: if $x=2$, then both statements $x \le 2$ and $x \le 3$ are correct.
2. Note that if $f \prec g$, then also $f \preceq g$. In plain English: if $f$ grows slower than $g$, then $f$ certainly grows no faster than $g$.
3. Note that we need to use a fancy $\preceq$ symbol instead of the standard less-or-equal sign $\le$, since the latter one is typically used as follows: $f \le g$ if $f(n) \le g(n)$ for all $n$. Hence, for example, $5n^2 \not \le n^2$, but $5n^2 \preceq n^2$. 

### Common rules

Before proceeding with visualizations, let's review the common rules of comparing the order of growth of functions arising frequently in algorithm analysis.

1. Multiplicative constants can be omitted: $c \cdot f \preceq f$. Examples: $5n^2 \preceq n^2$, $\frac{n^2}{3} \preceq n^2$.
2. Out of two polynomials, the one with larger degree grows faster: $n^a \preceq n^b$ for $0 \le a \le b$. Examples: $n \prec n^2$, $\sqrt{n} \prec n^{2/3}$, $n^2 \prec n^3$, $n^0 \prec \sqrt{n}$.
3. ==Any polynomial grows slower than any exponential:== $n^a \prec b^n$ for $a \ge 0, b>1$. Examples: $n^3 \prec 2^n$, $n^{10} \prec 1.1^n$.
4. ==Any polylogarithm grows slower than any polynomial:== $(\log n)^a \prec n^b$ for $a, b>0$. Examples: $(\log n)^3 \prec \sqrt{n}$, $n\log n \prec n^2$.
5. Smaller terms can be ommited: if $f \prec g$, then $f+g\preceq g$. Examples: $n^2+n \preceq n^2$, $2^n+n^9 \preceq 2^n$.

