/**
 * Given that type T is a group, denoted by
 *     G = (T,+,*,T(0))
 * we define a related abelian group, denoted by
 *     H = (lg<T>, *, ^(-1), lg<T>(T(0))).
 * 
 * We define the group homomorphisms G -> H and H -> G
 * where
 *     G := lg<T>(log(x))
 * and
 *     H := T(exp(x))
 * that allow converting between these two groups.
 * Thus, log : T -> T and exp : T -> T must be
 * implemented with the usual meaning.
 * 
 * lg<T> is a non-negative number type that models
 * T, but with the the following features:
 * 
 *     (1) Efficiently implements multiplication (reduces to addition by
 *         the property of logarithms).
 * 
 *     (2) It has a much larger range [0,b] where
 *             b := exp(numeric_limit<T>::max()),
 *         but is only closed under multiplication.
 * 
 *         Even if the result must eventually be
 *         converted back into a value of type T,
 *         it may be the case that only *intermediate*
 *         values in a computation would overflow T,
 *         but the final result may be converted to
 *         type T without overflowing. We provide
 *         a will_overflow : lg<T> -> bool predicate
 *         to determine this before the conversion.         
 * 
 * Additional comments
 * -------------------
 * (1) Operations like + : (lg<T>,lg<T>) -> lg<T> are not in the computational
 * basis of lg<T>. However, expression templates could efficiently model these
 * operations, e.g.,
 *     + : (L,R) -> sum_expr<L,R>.
 * When we convert an expression template, which may be deeply nested,
 * to lg<T> or T, there are many opportunities to do this conversion without
 * loss, or at least with less loss, e.g.,
 *     (lg<T>(x) + lg<T>(x)) + lg<T>(x) = lg<T>(3)*lg<T>(x).
 * 
 * An interesting underlying type T is one that accumulates
 * very little rounding error on addition, e.g., a type T that
 * implements + : (T,T) -> T using the Kahan summation algorithm
 * such that products of the form
 *     lg<T>(x1) * ... * lg<T>(xn),
 * which are transformed to
 *     lg<T>(log(x1) + ... + lg<T>(log(xn)),
 * have very little error.
 * 
 * 
 * Generic programming
 * -------------------
 * 
 * Any type T that models a ring (
 *     T,
 *     +,
 *     *,
 *     -,                       inverse additive operation, i.e., (-a) + a = T()
 *     /,                       inverse multiplicative operation, i.e., a / a = T(1)
 *     T()                      additive identity
 *     T(1)                     multiplicative identity
 * )
 * along with
 *     log : T -> T
 *     exp : T -> T             not strictly necessary if converting back not required
 * may be lifted to a group (
 *     lg<T>,
 *     *,
 *     /,                       lg<T>(a) / lg<T>(a) = lg<T>()
 *     lg<T>()                  group identity
 * )
 * 
 * Additional operations may also be supported by T to extend the computational
 * basis of lg<T>.
 * 
 * An obvious type for T is a floating point primitive, like double. However,
 * T may also be a more exocit type, like a symmetric invertible matrix?
 *     
 */

#pragma once

#include <cmath>
#include <limits>

using std::exp;
using std::log;
using std::sqrt;
using std::numeric_limits;

/**
 * Models a computational extension using the fact
 *     exp(log(a*b))==exp(log(a)+log(b)).
 * 
 * It has a range of values that is a subset of
 *     (0,e^m]
 * where m := numeric_limits<T>::maximum().
 */
template <typename T>
struct lg
{
    T k;

    // log : lg<T> -> lg<T>.
    auto log() const { return lg<T>{k}; };

    lg(lg const &) = default;

    // by default, constructs a value that is the multiplicative identity
    // (i.e., exp(0) = 1).
    lg() : k(T(0)) {}

    lg(T x) : k(log(x)) { assert(0 < x); };

    // operator to convert to type T.
    operator T() const { return exp(k); }
};

template <typename T>
struct ::std::numeric_limits<lg<T>>
{
    static constexpr auto max() { return lg<T>{number_limits<T>::max()}; }
    static constexpr auto min() { return lg<T>{number_limits<T>::min()}; }
    static constexpr auto is_signed() { return false; }
    static constexpr auto has_infinity() { return numeric_limits<T>::has_infinity(); }
    static constexpr auto infinity() { return lg<T>{numeric_limits<T>::infinity()}; }
};

template <typename T>
auto source_overflows(lg<T> const & x) { return lg<T>(numeric_limits<T>::max()) < x; }

template <typename T>
auto source_underflows(lg<T> const & x) { return numeric_limits<lg<T>>::max() < x; }

template <typename T>
auto inv(lg<T> const & x) { return lg<T>{-x.k}; }

template <typename T>
auto operator*(lg<T> const & x, lg<T> const & y) { return lg<T>{x.k + y.k}; }

template <typename T>
auto operator/(lg<T> const & x, lg<T> const & y) { return lg<T>{x.k + (-y.k)}; }

template <typename T>
auto operator<(lg<T> const & x, lg<T> const & y) { return x.k < y.k; }

template <typename T>
auto operator<=(lg<T> const & x, lg<T> const & y) { return x.k <= y.k; }

template <typename T>
auto operator==(lg<T> const & x, lg<T> const & y) { return x.k == y.k; }

template <typename T>
auto operator!=(lg<T> const & x, lg<T> const & y) { return x.k != y.k; }

template <typename T>
auto operator>(lg<T> const & x, lg<T> const & y) { return x.k > y.k; }

template <typename T>
auto operator>=(lg<T> const & x, lg<T> const & y) { return x.k >= y.k; }

/**
 * gamma : lg<T> -> lg<T>
 * 
 * Stirling's approximation
 * of the gamma function.
 */
template <typename T>
auto gamma(lg<T> const & x)
{
    using std::log;
    using std::sqrt;
    static const q = log(sqrt((T)2*M_PI));
    const auto y = (T)x;
    return lg<T>{q + log(sqrt(y)) + y * (T)(log(x)) + (-y)};
}

/**
 * log : lg<T> -> lg<T>
 * 
 * Logarithms are O(1) to compute in lg<T>.
 */
template <typename T>
auto log(lg<T> const & x) { return x.log(); }

/**
 * log : (lg<T>, T) -> lg<T>
 * 
 * log to some base b, i.e., log(x,b) solves y for b^y = x.
 */
template <typename T, typename U>
auto log(lg<T> const & x, U const & b)
{
    using std::log;
    return lg<T>{x.k / (T)log(b)};
}

template <typename T>
auto pow(lg<T> const & x, T const & e)
{
    return lg<T>{e * x.k};
}

template <typename T>
auto sqrt(lg<T> const & x) { return pow(x, T(0.5)); }

template <typename T>
auto nth_root(lg<T> const & x, T const & r) { return pow(x, T(1) / r); }

template <typename T>
constexpr auto sign(lg<T> const &) { return 1; }

template <typename T>
auto abs(lg<T> const & x) { return x; }

template <typename T>
auto floor(lg<T> const & x)
{
    // Laplace transform of f(t) := floor(e^t) is
    // L(f) = R(s)/s where R is the Riemann zeta
    // function,
    //     R(s) := sum 1/n^s from n=1 to infinity,
    // and thus
    //     L(f)(s) = (1/s) (1 + 1/2^s + 1/3^s + ...). 
    // Therefore,
    //     f := L^{-1}((1/s)(1 + 1/2^s + 1/3^s + ...),
    // which may be numerically computed.
    //
    // Can we efficiently compute this without overflowing
    // or underflowing on operations defined for T?
    //
    // Look into computing other operations, like sin,
    // using the Laplace transform.
    return 0;
}

template <typename T>
auto fac(int n)
{
    T s = T(0);
    // if T is a floating point type, then adding from smallest to largest
    // reduces round-off error.
    for (int i = 2; i <= n; ++i)
        s += log(i);
    return lg<T>{s};
}

/**
 * The exponential function
 *     exp : lg<T> -> lg<T>
 * may cause an overflow, just as 
 *     operator * : (T,T) -> T
 * may cause overflow or underflow on
 * the underlying type T.
 * 
 * We might prefer to deal with exp by
 * casting it to
 *     exp : lg<T> -> lg<lg<T>>,
 * but lg<T> does not define + : lg<T> and
 * thus cannot be used as a parameter of
 * lg.
 * 
 * Instead, we first convert lg<T> to T, which
 * naturally applies exp : T -> T, and thus
 * may cause an overflow or underflow.
 * 
 * These condition can be respectively checked with
 *     overflow_to<T> : lg<T> -> bool
 * and
 *     underflow_to<T> : lg<T> -> bool.
 * 
 * (Note: we would prefer to return an
 * optional<lg<T>>{} so that nothing is
 * returned if an overflow or underflow occurs,
 * but C++ does not play very well with
 * monads.)
 * 
 * The implementation of exp is trivial.
 */
template <typename T>
auto exp(lg<T> const & x) { return lg<T>{(T)x}; }

/**
 * Many elementary functions in the computational
 * basis of T are not in the computational basis
 * of lg<T>.
 * 
 * For example, assuming
 *     sin : T -> T
 * is defined over [T(0),T(2*pi)), we would like 
 * to compute
 *     sin : lg<T> -> lg<T>
 * by projecting values of type lg<T> onto the
 * interval [lg<T>(2),lg<T>(2*pi)) to be within
 * the range of T by doing the transformation
 *     s := lg<T>(x) - lg<T>(2*k*pi)
 * where
 *     k := floor(lg<T>(x) / lg<T>(2*pi))
 * and then do the computation in the
 * computational basis of T,
 *     sin(lg<T>(x)) := lg<T>(sin((T)s)).
 * 
 * However, operations like
 *     - : lg<T> -> lg<T> -> lg<T>
 * are not in the computational basis of lg<T>,
 * so we cannot do the transformation without
 * risk.
 * 
 * Instead, elsewhere we provide a safe monad
 * that automatically propagates overflow or
 * underflow information and acts appropriately,
 * e.g., lifting
 *     f : T -> T
 * to
 *     f : safe<lg<T>> -> safe<lg<T>>.
 * 
 * lg<T> models the concept of Safe<T>, so any operation
 * on T may be lifted to lg<T>. In full generality,
 * f may be a function f : X -> Y or f : X -> Y -> Z.
 * As long as X, Y, and Z model rings, e.g.,
 *     (X, +, *, -, X(0)),
 * as required by lg<X>, then they should also work.
 */
};
