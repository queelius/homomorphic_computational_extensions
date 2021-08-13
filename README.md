<script type="text/x-mathjax-config">
    MathJax.Hub.Config({
      tex2jax: {
        skipTags: ['script', 'noscript', 'style', 'textarea', 'pre'],
        inlineMath: [['$','$']]
      }
    });
  </script>
  <script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>
  
# Homomorphic computational extensions

We consider homomorphisms which are based on computational concerns which are
used to transform inefficient or lossy computations over some original
domain $T$ into a conceptually equivalent group \( \hat{T} \) over a restricted set
of operations. If the original problem can be solved using these restricted
operations, then we may transform $T$ into $\hat{T}$ and efficiently perform the
computations.

Sometimes, the entire solution cannot be transformed back to $T$, but some
queries can, such as predicates, e.g., is $a + c < b + c$ even though
$a+c$ or $b+c$ may not be in the domain of $T$.

Given that type $T$ is a ring

$$
    (T,+,*,-,T(0)),
$$

we define a group

$$
    (\hat{T}, *, ^{-1}, \hat{T}(0))
$$

with homomorphisms $F$ and $G$

$$
    F : T -> \hat{T}\\
    G : \hat{T} -> T
$$

where **if** $F$ and $G$ are inverses, e.g.,

$$
    F . G = id_{\hat{T}}
$$
and
$$
    G . F = id_{T},
$$

then $T$ and $\hat{T}$ are isomorphic, although this is not generally the case.
 
We make a additional requirements that $T$ should be a
regular type, e.g., assignment ($=$) and equality ($==$) is defined, and $T$
should have a total ordering $<$ defined.

As a result, $\hat{T}$ will also be a regular type with some ordering relation.

$F$ must map values such that $\hat{T}$ will have the same
ordering relation as $T$ on values in the range
of $T$ and will *extend* that relation to any values outside the range of $T$
in the following way: if $a < b$ and $a + c$ or $b + c$ is not in the range of
$T$, then

$$
\hat{a} + \hat{c} < \hat{b} + \hat{c}.
$$
 
This is usually done by making $F$ a strictly monotonically increasing
function.

The fact that a value of type $\hat{T}$ must
initially be constructed from a value of type
$T$ means that these constructions are lossless.
However, since $\hat{T}$ is a group with
opeations, namely $*$, a value of type
$\hat{T}$ may not be a value in $T$. Typically,
the value $\hat{T}$ would conceptually map to
would be outside the range of $T$, e.g., either
too small or too large.

We also can expect, depending on $F$ and $G$, some
independent sources of loss, e.g., if $F$
introduces some minor loss due to rounding
or truncation. 

The operation

$$
    * : \hat{T} \times \hat{T} \mapsto \hat{T}
$$

is defined as

$$
    a * b := F ( G a + G b ),
$$

which is associative by the associativity of $+$.

The inverse operation

$$
    ^{-1}: \hat{T} \mapsto \hat{T}
$$

is defined as

$$
    a^{-1} := f ( -g(a) ).
$$    

Finally, the identity

$$
    \hat{T}(T(0))
$$

must be given by

$$
    a * a^{-1} := F ( G a + G ( a^{-1} ),
$$

thus we see that $G$ must satisfy

$$
    ( G a^{-1} ) + (G a) = T(0),
$$

i.e., $F$ and $G$ must map inverses to inverses and $F$ and $G$ must map
identity to identity.

$\hat{T}$ is intended to make computations
more precise, faster, or less suspetible to underflows or overflows,
than $T$ over a more restricted set of operations, where the computational
basis is

$$
    \{+, ^{-1}\}.
$$

Common use-case:

When dealing with very large or small numbers in numerical computation,
such as computing likelihoods, it is frequently faster and more precise
to work with logarithms of numbers and mapping them back to their
actual values only when needed. This allows multiplication to be as
simple and fast as addition, and avoids most intermediate values that
would otherwise result in underflows or overflows even when the final
result is within the range of $T$.

If the final result is not within the range of $T$, which can be checked,
and the actual value is needed for additional computations, other steps
may be taken, e.g., map the result to a slow bignum data type.
