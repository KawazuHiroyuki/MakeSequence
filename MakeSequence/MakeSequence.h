#pragma once

#include <algorithm>
#include <memory>
#include <cstddef>

namespace utility {

template <typename Type, template<class, class> class Containter, typename Increment> // std::function<Type(Type)>
inline Containter<Type, std::allocator<Type>> makeSequence(Type start, std::size_t size, Increment increment)
{
    Containter<Type, std::allocator<Type>> sequence(size);
    Type element = start;
    std::generate(sequence.begin(), sequence.end(),
        [&increment, &element]() {
            auto temp = element;
            element = increment(element);
            return temp;
        });
    return sequence;
}
}
