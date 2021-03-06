#pragma once

#include "common.h"
#include "random.h"

#include <algorithm>
#include <iterator>

namespace jngen {

// TODO: deprecate random_shuffle as done in testlib.h

template<typename Iterator>
void shuffle(Iterator begin, Iterator end) {
    ensure(end >= begin, "Cannot shuffle range of negative length");
    size_t size = end - begin;
    for (size_t i = 1; i < size; ++i) {
        std::swap(*(begin + i), *(begin + rnd.next(i + 1)));
    }
}

template<typename Iterator>
auto choice(Iterator begin, Iterator end)
        -> typename std::iterator_traits<Iterator>::value_type
{
    return rnd.choice(begin, end);
}

template<typename Container>
typename Container::value_type choice(const Container& container) {
    return rnd.choice(container);
}

template<typename T>
T choice(std::initializer_list<T> ilist) {
    return choice(ilist.begin(), ilist.end());
}

} // namespace jngen

using jngen::shuffle;
using jngen::choice;
