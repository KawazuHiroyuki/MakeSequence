
#include <iostream>
#include <string>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "MakeSequence.h"

template <typename Container>
void print(const std::string& brief, const Container& sequence)
{
    std::cout << brief << ": ";
    for (auto element : sequence) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

template <
    typename Key,
    typename Type,
    template<class, class, class, class> class Containter
>
void print(const std::string& brief, const Containter<Key, Type, std::less<Key>, std::allocator<std::pair<const Key, Type>>>& sequence)
{
    std::cout << brief << ": ";
    for (auto element : sequence) {
        std::cout << "[" << element.first << ", " << element.second << "]";
    }
    std::cout << std::endl;
}

template <
    typename Key,
    typename Type,
    template<class, class, class, class, class> class Containter
>
void print(const std::string& brief, const Containter<Key, Type, std::hash<Key>, std::equal_to<Key>, std::allocator<std::pair<const Key, Type>>>& sequence)
{
    std::cout << brief << ": ";
    for (auto element : sequence) {
        std::cout << "[" << element.first << ", " << element.second << "]";
    }
    std::cout << std::endl;
}

template <typename T, std::size_t N>
class Array : public std::array<T, N>
{
};


int main()
{
    std::function<double(double)> function1 = [](double x) { return x + 1.02020; };
    struct Functor 
    {
        double operator()(double x)
        {
            return x + 369.8;
        }
    };


    // tempalte <class T, std::size_t N>
    {
        // std::array
        auto sequence = utility::makeSequence<double, 10>(-9.99, [](double x) { return x + 2.551; });
        print("std::array 0", sequence);

        auto sequence1 = utility::makeSequence<double, 12, std::array>(74.99, [](double x) { return x + 2.551; });
        print("std::array 1", sequence1);

        auto sequence2 = utility::makeIndexSequence<12>(2);
        print("std::array 2", sequence2);

        auto sequence3 = utility::makeSequence<double, 12, Array>(74.99, [](double x) { return x + 69; });
        print("std::array 3", sequence3);

        auto sequence4 = utility::makeIndexSequence<12, Array>();
        print("std::array 4", sequence4);

        auto sequence5 = utility::makeSequence<double, 12, Array>(5);
        print("std::array 5", sequence5);
    }

    // template <class T, class Allocator = allocator<T>>
    {
        // std::deque
        auto sequence = utility::makeSequence<double, std::deque>(10, -2.6, [](double x) { return x + 2.551; });
        print("std::deque 0", sequence);
    }

    {
        // std::forward_list
        auto sequence = utility::makeSequence<double, std::forward_list>(10, -34.6, [](double x) { return x + 3.9; });
        print("std::forward_list 0", sequence);
    }

    {
        // std::list
        auto sequence = utility::makeSequence<double, std::list>(10, -23, [](double x) { return x - 3.6; });
        print("std::list 0", sequence);
    }

    {
        // std::vector
        auto sequence = utility::makeSequence<double, std::vector>(20, -22, [](double x) { return x+2.1; });
        print("std::vector 0", sequence);

        auto sequence1 = utility::makeSequence<double, std::vector>(20);
        print("std::vector 1", sequence1);

        auto sequence2 = utility::makeSequence<double, std::vector>(20, 300);
        print("std::vector 2", sequence2);

        auto sequence3 = utility::makeSequence<double>(20, 300);
        print("std::vector 3", sequence3);

        auto sequence4 = utility::makeIndexSequence(10);
        print("std::vector 4", sequence4);

        auto sequence5 = utility::makeIndexSequence(10, 1);
        print("std::vector 5", sequence5);

        auto sequence6 = utility::makeIndexSequence<std::list>(10);
        print("std::vector 6", sequence6);

        auto sequence7 = utility::makeSequence<double>(20, 300, function1);
        print("std::vector 7", sequence7);

        auto sequence8 = utility::makeSequence<double>(20, 300, Functor());
        print("std::vector", sequence8);
    }

#if 0
    // template <class T, class Container = deque<T>>
    {
        // std::queue
        auto sequence = utility::makeSequence<double, std::queue>(-23, 10, [](double x) { return x - 3.6; });
        //print(sequence);
    }

    {
        // std::stack
        //auto sequence = utility::makeSequence<double, std::stack>(-1, 10, [](double x) { return x - 6.9; });
        //print(sequence);
    }

    {
        // std::priority_queue
    }
#endif

    // tempalte <class Key, class T, class Compare = less<Key>, class Allocator = allocator<pair<const Key, T>>
    {
        // std::set
        auto sequence = utility::makeSequence<double, std::set>(20, -22, [](double x) { return x + 2.1; });
        print("std::set 0", sequence);

        auto sequence1 = utility::makeSequence<double, std::set>(20, 2);
        print("std::set 1", sequence1);

        auto sequence2 = utility::makeIndexSequence<std::set>(20, 2);
        print("std::set 2", sequence2);
    }

    {
        // std::multiset
        auto sequence = utility::makeSequence<double, std::multiset>(20, -22, [](double x) { return x + 2.1; });
        print("std::multiset 0", sequence);

        auto sequence1 = utility::makeSequence<double, std::multiset>(20, 2);
        print("std::multiset 1", sequence1);

        auto sequence2 = utility::makeIndexSequence<std::multiset>(20, 2);
        print("std::multiset 2", sequence2);
    }

    // tempalte <class Key, class Hash = std::hash<Key>, class Pred = std::equal_to<Key>, class Allocator = std::allocator<Key>>
    {
        // std::unordered_set
        auto sequence = utility::makeSequence<double, std::unordered_set>(20, -22, [](double x) { return x + 2.1; });
        print("std::unordered_set 0", sequence);

        auto sequence1 = utility::makeIndexSequence<std::unordered_set>(20, -22);
        print("std::unordered_set 1", sequence1);
    }

    {
        // std::unordered_multiset
        auto sequence = utility::makeSequence<double, std::unordered_multiset>(20, -22, [](double x) { return x; });
        print("std::unordered_multiset 0", sequence);
    }


    // tempalte <class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
    {
        // std::map
        auto sequence = utility::makeSequence<std::string, int, std::map>(20, { "Key0", 0 }, [](std::pair<std::string, int> x) { return std::make_pair(std::string("Key" + std::to_string(x.second + 1)), x.second + 1); });
        print("std::map 0", sequence);

        //auto sequence1 = utility::makeSequence<std::string, int>(20, { "Key1", 1 }, [](std::pair<std::string, int> x) { return std::make_pair(std::string("Key" + std::to_string(x.second + 1)), x.second + 1); });
        //print("std::map 1", sequence1);
    }

    {
        // std::multimap
        auto sequence = utility::makeSequence<std::string, int, std::multimap>(20, { "Key0", 0 }, [](std::pair<std::string, int> x) { return std::make_pair(std::string("Key" + std::to_string(x.second + 1)), x.second + 1); });
        print("std::multimap 0", sequence);

        auto sequence1 = utility::makeSequence<std::string, int, std::multimap>(20, { "Key0", 0 }, [](std::pair<std::string, int> x) { return x; });
        print("std::multimap 1", sequence1);
    }

    // tempalte <class Key, class T, class Hash = std::hash<Key>, class Pred = std::equal_to<Key>, class Allocator = std::allocator<std::pair<const Key, class T>>>
    {
        // std::unordered_map
        auto sequence = utility::makeSequence<std::string, int, std::unordered_map>(20, { "Key0", 0 }, [](std::pair<std::string, int> x) { return std::make_pair(std::string("Key" + std::to_string(x.second + 1)), x.second + 1); });
        print("std::unordered_map 0", sequence);
    }

    {
        // std::unordered_multimap
        auto sequence = utility::makeSequence<std::string, int, std::unordered_multimap>(20, { "Key0", 0 }, [](std::pair<std::string, int> x) { return std::make_pair(std::string("Key" + std::to_string(x.second + 1)), x.second + 1); });
        print("std::unordered_multimap 0", sequence);
    }
}
