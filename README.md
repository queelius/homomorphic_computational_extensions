Homomorphic computational extensions
================
Alex Towell
3/5/2022

We consider homomorphisms which are based on computational concerns which are used to
transform inefficient or lossy computations over some original domain `T` into a
conceptually equivalent group `T\`` over a restricted set of operations.

If the original problem can be solved using these restricted operations, then we may
transform `T` into `T\`` and efficiently perform the computations.
Sometimes, the entire solution cannot be transformed back to `T`, but the restricted
set of functions or operations may still be sufficient, e.g., evaluating
`a + c < b + c` even though `a+c` or `b+c` may not be in the domain of `T`.
