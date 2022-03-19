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
#include <map>
#include <deque>

namespace utility
{

// Increment = Type (Type);

template <typename Type>
using Incrementer = std::function<Type(Type)>;

template <typename Type>
struct DefaultIncrementer
{
    Type operator()(Type x) const
    {
        return ++x;
    }
};


// tempalte <class T, std::size_t N>
//   std::array
template <
    typename Type,
    std::size_t Size,
    template<class, std::size_t> class Containter = std::array,
    typename Increment = typename Incrementer<Type>
>
inline auto makeSequence(Type start = Type(), Increment increment = DefaultIncrementer<Type>())
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
    typename Increment = typename Incrementer<Type>
>
inline auto makeSequence(std::size_t size, Type start = Type(), Increment increment = DefaultIncrementer<Type>())
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
    template<class, template<class, class> class> class ContainterAdapter/* = std::queue<Type, std::deque<Type>>*/,
    template<class, class> class Container /*= std::deque*/,
    typename Increment = typename Incrementer<Type>
>
inline auto makeSequence(std::size_t size, Type start = Type(), Increment increment = DefaultIncrementer<Type>())
{
    ContainterAdapter<Type, Container> sequence;
    Type element = start;
    for (auto index : makeIndexSequence(size)) {
        sequence.push(element);
        element = increment(element);
    }
    return sequence;
}

// template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
//   std::priority_queue

#endif

// tempalte <class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
//   std::set
//   std::multiset
#if 1
template <
    typename Key,
    template<class, class, class> class Containter /*= std::set*/,
    typename Increment = typename Incrementer<Key>
>
inline auto makeSequence(std::size_t size, Key start = Key(), Increment increment = DefaultIncrementer<Key>())
{
    Containter<Key, std::less<Key>, std::allocator<Key>> sequence;
    Key element = start;
    for (auto index : makeIndexSequence(size)) {
        sequence.insert(element);
        element = increment(element);
    }
    return sequence;
}

template <
    template<class, class, class> class Containter /*= std::set*/
>
inline auto makeIndexSequence(std::size_t size, std::size_t start = std::size_t())
{
    auto sequence = makeSequence<std::size_t, Containter>(size, start, DefaultIncrementer<std::size_t>());
    return sequence;
}
#endif

#if 1
// tempalte <class Key, class Hash = std::hash<Key>, class Pred = std::equal_to<Key>, class Allocator = std::allocator<Key>>
//   std::unordered_set
//   std::unordered_multiset
template <
    typename Key,
    template<class, class, class, class> class Containter /*= std::unordered_set*/,
    typename Increment = typename Incrementer<Key>
>
inline auto makeSequence(std::size_t size, Key start = Key(), Increment increment = DefaultIncrementer<Key>())
{
    Containter<Key, std::hash<Key>, std::equal_to<Key>, std::allocator<Key>> sequence;
    Key element = start;
    for (auto index : makeIndexSequence(size)) {
        sequence.insert(element);
        element = increment(element);
    }
    return sequence;
}

template <
    template<class, class, class, class> class Containter /*= std::unordered_set*/
>
inline auto makeIndexSequence(std::size_t size, std::size_t start = std::size_t())
{
    auto sequence = makeSequence<std::size_t, Containter>(size, start, DefaultIncrementer<std::size_t>());
    return sequence;
}
#endif

// tempalte <class Key, class T, class Compare = less<Key>, class Allocator = allocator<pair<const Key, T>>
//   std::map
//   std::multimap
template <
    typename Key,
    typename Type,
    template<class, class, class, class> class Containter /*= std::map*/,
    typename Increment = typename Incrementer<Type>
>
inline auto makeSequence(std::size_t size, std::pair<Key, Type> start, Increment increment)
{
    Containter<Key, Type, std::less<Key>, std::allocator<std::pair<const Key, Type>>> sequence;
    std::pair<Key, Type> element = start;
    for (auto index : makeIndexSequence(size)) {
        sequence.insert(element);
        element = increment(element);
    }
    return sequence;
}

// tempalte <class Key, class T, class Hash = std::hash<Key>, class Pred = std::equal_to<Key>, class Allocator = std::allocator<std::pair<const Key, class T>>>
//   std::unordered_map
//   std::unordered_multimap
template <
    typename Key,
    typename Type,
    template<class, class, class, class, class> class Containter /*= std::unordered_map*/,
    typename Increment = typename Incrementer<Type>
>
inline auto makeSequence(std::size_t size, std::pair<Key, Type> start, Increment increment)
{
    Containter<Key, Type, std::hash<Key>, std::equal_to<Key>, std::allocator<std::pair<const Key, Type>>> sequence;
    std::pair<Key, Type> element = start;
    for (auto index : makeIndexSequence(size)) {
        sequence.insert(element);
        element = increment(element);
    }
    return sequence;
}


#if 0
// template <class T>
//   std::valarray
//   std::
template <
    typename Type,
    template<class> class Containter = std::valarray,
    typename Increment = typename Incrementer<Type>
>
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

template <
    template<class> class Containter = std::valarray
>
inline auto makeIndexSequence(std::size_t size, std::size_t start = std::size_t())
{
    auto sequence = makeSequence<std::size_t, Containter, std::function<std::size_t(std::size_t)>>(size, start, [](std::size_t x) { return ++x; });
    return sequence;
}
#endif

} // namespace utility
