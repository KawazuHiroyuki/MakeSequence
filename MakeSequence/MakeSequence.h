#pragma once

#include <functional>
#include <algorithm>
#include <memory>
#include <cstddef>
#include <vector>
#include <array>
#include <valarray>
#include <queue>
#include <set>
#include <numeric>

namespace utility
{

// Increment = Type (Type);

// tempalte <class T, std::size_t N>
//   std::array
template <
    typename Type,
    std::size_t Size,
    template<class, std::size_t> class Containter = std::array,
    typename Increment = std::function<Type(Type)>
>
inline auto makeSequence(Type start = Type(), Increment increment = [](Type x) { return ++x; })
{
    Containter<Type, Size> sequence;
    Type element = start;
    std::generate(sequence.begin(), sequence.end(),
        [&increment, &element]() {
            auto temp = element;
            element = increment(element);
            return temp;
        });
    return sequence;
}

template <
    std::size_t Size,
    template<class, std::size_t> class Containter = std::array
>
inline auto makeIndexSequence(std::size_t start = std::size_t())
{
    Containter<std::size_t, Size> sequence;
    std::iota(sequence.begin(), sequence.end(), start);
    return sequence;
}

// template <class T, class Allocator = allocator<T>>
//   std::deque
//   std::forward_list
//   std::list
//   std::vector
template <
    typename Type,
    template<class, class> class Containter = std::vector,
    typename Increment = std::function<Type(Type)>
>
inline auto makeSequence(std::size_t size, Type start = Type(), Increment increment = [](Type x) { return ++x; })
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

template <
    template<class, class> class Containter = std::vector
>
inline auto makeIndexSequence(std::size_t size, std::size_t start = std::size_t())
{
    Containter<std::size_t, std::allocator<std::size_t>> sequence(size);
    std::iota(sequence.begin(), sequence.end(), start);
    return sequence;
}

// template <class T, class Container = deque<T>>
//   std::queue
//   std::stack
#if 0
template <
    typename Type,
    template<class, template<class, class> class> class Containter = std::queue<Type>,
    typename Increment = std::function<Type(Type)>
>
inline auto makeSequence(std::size_t size, Type start = Type(), Increment increment = [](Type x) { return ++x; })
{
}
#endif

// tempalte <class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
//   std::set
//   std::multiset
#if 0
template <
    typename Type,
    template<class, class, class> class Containter = std::set,
    typename Increment = std::function<Type(Type)>
>
inline auto makeSequence(std::size_t size, Type start = Type(), Increment increment = [](Type x) { return ++x; })
{
    Containter<Type, less<Type>, std::allocator<Type>> sequence(size);
    Type element = start;
    std::generate(sequence.begin(), sequence.end(),
        [&increment, &element]() {
            auto temp = element;
            element = increment(element);
            return temp;
        });
    return sequence;
}

template <
    template<class, class, class> class Containter = std::set
>
inline auto makeIndexSequence(std::size_t size, std::size_t start = std::size_t())
{
    auto sequence = makeSequence<std::size_t, Containter, std::function<std::size_t(std::size_t)>>(size, start, [](std::size_t x) { return ++x; });
    return sequence;
}
#endif

// tempalte <class Key, class T, class Compare = less<Key>, class Allocator = allocator<pair<const Key, T>>
//   std::map
//   std::multimap


#if 0
// template <class T>
//   std::valarray
//   std::
template <typename Type, template<class> class Containter = std::valarray, typename Increment = std::function<Type(Type)>>
inline auto makeSequence(std::size_t size, Type start = Type(), Increment increment = [](Type x) { return ++x; })
{
    Containter<Type> sequence(size);
    Type element = start;
    std::generate(sequence.begin(), sequence.end(),
        [&increment, &element]() {
            auto temp = element;
            element = increment(element);
            return temp;
        });
    return sequence;
}

template <template<class> class Containter = std::valarray>
inline auto makeIndexSequence(std::size_t size, std::size_t start = std::size_t())
{
    auto sequence = makeSequence<std::size_t, Containter, std::function<std::size_t(std::size_t)>>(size, start, [](std::size_t x) { return ++x; });
    return sequence;
}
#endif

} // namespace utility
