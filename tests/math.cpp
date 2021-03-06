#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../jngen.h"

#include <utility>

BOOST_AUTO_TEST_SUITE(math)

BOOST_AUTO_TEST_CASE(primes) {
    rnd.seed(123);

    for (long long x: {
            1ll,
            10ll,
            25326001ll,
            1000000000000000000ll,
            2147483648ll
    } ) {
        BOOST_CHECK(!isPrime(x));
    }

    for (long long x: {
            2ll,
            3ll,
            5ll,
            1000000009ll,
            2147483647ll,
            313287970493ll,
            153204046992197ll,
            184917989787916379ll
    } ) {
        BOOST_CHECK(isPrime(x));
    }

    typedef std::pair<long long, long long> pll;

    for (pll p: {
        pll{2, 10},
        pll{1000000008, 1000000009},
        pll{581957284756284, 691827582758172},
        pll{2, 1000000000000000000},
        pll{1000000000000, 1000000000040}
    } ) {
        rndm.randomPrime(p.first, p.second);
    }

    BOOST_CHECK_THROW(rndm.randomPrime(1, 1), jngen::Exception);
    BOOST_CHECK_THROW(rndm.randomPrime(14, 16), jngen::Exception);
}

BOOST_AUTO_TEST_SUITE_END()
