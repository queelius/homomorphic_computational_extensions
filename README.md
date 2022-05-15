Homomorphic computational extensions
================
Alex Towell
3/5/2022

We consider homomorphisms which are based on computational concerns
which are used to transform inefficient or lossy computations over some
original domain
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
into a conceptually equivalent group
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
over a restricted set of operations. If the original problem can be
solved using these restricted operations, then we may transform
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
into
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
and efficiently perform the computations.

Sometimes, the entire solution cannot be transformed back to
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T"),
but some queries can, such as predicates, e.g., is
![a + c \< b + c](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;a%20%2B%20c%20%3C%20b%20%2B%20c "a + c < b + c")
even though
![a+c](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;a%2Bc "a+c")
or
![b+c](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;b%2Bc "b+c")
may not be in the domain of
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T").

Given that type
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
is a ring

![(T,+,\*,-,T(0)),](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%28T%2C%2B%2C%2A%2C-%2CT%280%29%29%2C "(T,+,*,-,T(0)),")

we define a group

![(\hat{T}, \*, ^{-1}, \hat{T}(0))](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%28%5Chat%7BT%7D%2C%20%2A%2C%20%5E%7B-1%7D%2C%20%5Chat%7BT%7D%280%29%29 "(\hat{T}, *, ^{-1}, \hat{T}(0))")

with homomorphisms
![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
and
![G](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;G "G")

![F : T \mapsto \hat{T}\\\\ G : \hat{T} \mapsto T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F%20%3A%20T%20%5Cmapsto%20%5Chat%7BT%7D%5C%5C%20G%20%3A%20%5Chat%7BT%7D%20%5Cmapsto%20T "F : T \mapsto \hat{T}\\ G : \hat{T} \mapsto T")

where if
![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
and
![G](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;G "G")
are inverses, e.g.,

![F . G = id\_{\hat{T}}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F%20.%20G%20%3D%20id_%7B%5Chat%7BT%7D%7D "F . G = id_{\hat{T}}")

and

![G . F = id\_{T},](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;G%20.%20F%20%3D%20id_%7BT%7D%2C "G . F = id_{T},")

then
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
and
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
are isomorphic, although this is not generally the case.

We make a additional requirements that
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
should be a regular type, e.g., assignment
(![=](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%3D "="))
and equality
(![==](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%3D%3D "=="))
are defined, and
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
should have a total ordering
![\<](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%3C "<")
defined. As a result,
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
will also be a regular type with some ordering relation.

![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
must map values such that
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
will have the same ordering relation as
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
on values in the range of
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
and will extend that relation to any values outside the range of
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
in the following way: if
![a \< b](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;a%20%3C%20b "a < b")
and
![a + c](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;a%20%2B%20c "a + c")
or
![b + c](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;b%20%2B%20c "b + c")
is not in the range of
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T"),
then

![\hat{a} + \hat{c} \< \hat{b} + \hat{c}.](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7Ba%7D%20%2B%20%5Chat%7Bc%7D%20%3C%20%5Chat%7Bb%7D%20%2B%20%5Chat%7Bc%7D. "\hat{a} + \hat{c} < \hat{b} + \hat{c}.")

This is usually done by making
![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
a strictly monotonically increasing function.

The fact that a value of type
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
must initially be constructed from a value of type
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
means that these constructions are lossless. However, since
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
is a group with operations, namely
![\*](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%2A "*"),
a value of type
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
may not be a value in
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T").
Typically, the value
![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
would conceptually map to would be outside the range of
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T"),
e.g., either too small or too large.

We also can expect, depending on
![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
and
![G](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;G "G"),
some independent sources of loss, e.g., if
![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
introduces some minor loss due to rounding or truncation.

The operation

![\* : \hat{T} \times \hat{T} \mapsto \hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%2A%20%3A%20%5Chat%7BT%7D%20%5Ctimes%20%5Chat%7BT%7D%20%5Cmapsto%20%5Chat%7BT%7D "* : \hat{T} \times \hat{T} \mapsto \hat{T}")

is defined as

![a \* b := F ( G a + G b ),](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;a%20%2A%20b%20%3A%3D%20F%20%28%20G%20a%20%2B%20G%20b%20%29%2C "a * b := F ( G a + G b ),")

which is associative by the associativity of
![+](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%2B "+").

The inverse operation

![^{-1}: \hat{T} \mapsto \hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5E%7B-1%7D%3A%20%5Chat%7BT%7D%20%5Cmapsto%20%5Chat%7BT%7D "^{-1}: \hat{T} \mapsto \hat{T}")

is defined as

![a^{-1} := f ( -g(a) ).](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;a%5E%7B-1%7D%20%3A%3D%20f%20%28%20-g%28a%29%20%29. "a^{-1} := f ( -g(a) ).")

Finally, the identity

![\hat{T}(T(0))](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D%28T%280%29%29 "\hat{T}(T(0))")

must be given by

![a \* a^{-1} := F ( G a + G ( a^{-1} ),](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;a%20%2A%20a%5E%7B-1%7D%20%3A%3D%20F%20%28%20G%20a%20%2B%20G%20%28%20a%5E%7B-1%7D%20%29%2C "a * a^{-1} := F ( G a + G ( a^{-1} ),")

thus we see that
![G](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;G "G")
must satisfy

![( G a^{-1} ) + (G a) = T(0),](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%28%20G%20a%5E%7B-1%7D%20%29%20%2B%20%28G%20a%29%20%3D%20T%280%29%2C "( G a^{-1} ) + (G a) = T(0),")

i.e.,
![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
and
![G](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;G "G")
must map inverses to inverses and
![F](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;F "F")
and
![G](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;G "G")
must map identity to identity.

![\hat{T}](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5Chat%7BT%7D "\hat{T}")
is intended to make computations more precise, faster, or less
susceptible to underflows or overflows over a more restricted set of
operations than
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T")
where the computational basis is

![\\{+, ^{-1}\\}.](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;%5C%7B%2B%2C%20%5E%7B-1%7D%5C%7D. "\{+, ^{-1}\}.")

## Use case: applying likelihood functions to observed data

When dealing with very large or small numbers in numerical computation,
such as computing likelihoods, it is frequently faster and more precise
to work with logarithms of numbers and mapping them back to their actual
values only when needed.

This allows multiplication to be as simple and fast as addition, and
avoids most intermediate values that would otherwise result in
underflows or overflows even when the final result is within the range
of
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T").

If the final result is not within the range of
![T](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D&space;%5Cbg_white&space;T "T"),
which can be checked, and the actual value is needed for additional
computations, other steps may be taken, e.g., map the result to a slow
bignum data type.
