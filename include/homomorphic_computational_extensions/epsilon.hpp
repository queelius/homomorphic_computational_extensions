#pragma once
#include <cmath>
#include <algorithm>

using std::exp;
using std::abs;

namespace alex::math
{
    namespace
    {
        template <typename T>
        T distance(T const & a, T const & b) { return abs(a-b); }
    }

    /**
     * Due to computational constraints, like memory or time,
     * computed values may not correspond to mathematical
     * truth.
     *
     * Given that two values are close, we have an implicit
     * bias that they are the same but differ due to computational or
     * measurement constraints.
     *
     * This uncertainty is characterized by the attribute eps.
     *
     * Even if T is totally ordered, epsilon<T> is only partially
     * ordered. Any two values a,b in T for which
     *     distance(a,b) <= max(a.eps,b.eps)
     * are equivalent, i.e., potentially the same value.
     *
     * Note that not only is epsilon<T> a partial relation, but it is also
     * a non-transitive relation since
     *     a == b && b == c does not imply a == c
     * and similiarly for the other predicates.
     */
    template <typename T>
    class epsilon
    {
    public:
        epsilon(epsilon const & copy) :
            value(copy.value), eps(copy.eps) {}

        epsilon(T x, T eps) :
            value(move(x)), eps(move(eps)) {}

        epsilon & operator=(epsilon const & rhs)
        {
            value = rhs.value;
            eps = rhs.eps;
        }

        operator T() const { return value; }

    private:
        T value;
        T eps;
    };

    template <typename T>
    bool operator==(epsilon<T> const & x, epsilon<T> const & y)
    {
        return distance(x.value,y.value) <= max(x.eps,y.eps);
    }

    template <typename T>
    bool operator!=(epsilon<T> const & x, epsilon<T> const & y)
    {
        return max(x.eps,y.eps) < distance(x.value,y.value);
    }

    template <typename T>
    bool operator>(epsilon<T> const & x, epsilon<T> const & y)
    {
        return x != y && y.value < x.value;
    }

    template <typename T>
    bool operator<(epsilon<T> const & x, epsilon<T> const & y)
    {
        return x != y && x.value < y.value;
    }

    template <typename T>
    bool operator<=(epsilon<T> const & x, epsilon<T> const & y)
    {
        return x == y || x.value < y.value;
    }

    template <typename T>
    bool operator>=(epsilon<T> const & x, epsilon<T> const & y)
    {
        return x == y && y.value > x.value;
    }

    // We allow values of type epsilon<T> to also be wrapped into an epsilon
    // type by lifting
    //     distance : T -> T -> T
    // to
    //     distance : epsilon<T> -> epsilon<T> -> epsilon<T>.
    template <typename T>
    epsilon<T> distance(epsilon<T> const & a, epsilon<T> const & b)
    {
        return epsilon<T>(distance(a.vaue,b.value),max(a.eps,b.eps));
    }

    struct epsilon_map
    {

    }


}
