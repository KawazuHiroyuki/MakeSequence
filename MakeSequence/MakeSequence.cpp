// MakeSequence.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

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
void print(const Container& sequence)
{
    for (auto element : sequence) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

template <typename T, std::size_t N>
class Array : public std::array<T, N>
{

};


int main()
{
    std::cout << "Hello World!\n";

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
        // array
        auto sequence = utility::makeSequence<double, 10>(-9.99, [](double x) { return x + 2.551; });
        print(sequence);

        auto sequence1 = utility::makeSequence<double, 12, std::array>(74.99, [](double x) { return x + 2.551; });
        print(sequence1);

        auto sequence2 = utility::makeIndexSequence<12>();
        print(sequence2);

        auto sequence3 = utility::makeSequence<double, 12, Array>(74.99, [](double x) { return x + 69; });
        print(sequence3);

        auto sequence4 = utility::makeIndexSequence<12, Array>();
        print(sequence4);
    }

    // template <class T, class Allocator = allocator<T>>
    {
        // deque
        auto sequence = utility::makeSequence<double, std::deque>(10, -2.6, [](double x) { return x + 2.551; });
        print(sequence);
    }

    {
        // forward_list
        auto sequence = utility::makeSequence<double, std::forward_list>(10, -34.6, [](double x) { return x + 3.9; });
        print(sequence);
    }

    {
        // list
        auto sequence = utility::makeSequence<double, std::list>(10, -23, [](double x) { return x - 3.6; });
        print(sequence);
    }

    {
        // vector
        auto sequence = utility::makeSequence<double, std::vector>(20, -22, [](double x) { return x+2.1; });
        print(sequence);

        auto sequence1 = utility::makeSequence<double, std::vector>(20);
        print(sequence1);

        auto sequence2 = utility::makeSequence<double, std::vector>(20, 300);
        print(sequence2);

        auto sequence3 = utility::makeSequence<double>(20, 300);
        print(sequence3);

        auto sequence4 = utility::makeIndexSequence(10);
        print(sequence4);

        auto sequence5 = utility::makeIndexSequence(10, 1);
        print(sequence5);

        auto sequence6 = utility::makeIndexSequence<std::list>(10);
        print(sequence6);

        auto sequence7 = utility::makeSequence<double>(20, 300, function1);
        print(sequence7);

        auto sequence8 = utility::makeSequence<double>(20, 300, Functor());
        print(sequence8);
    }

    // template <class T, class Container = deque<T>>
    {
        // queue
        //auto sequence = utility::makeSequence<double, std::queue>(-23, 10, [](double x) { return x - 3.6; });
        //print(sequence);
    }

    {
        // stack
        //auto sequence = utility::makeSequence<double, std::stack>(-1, 10, [](double x) { return x - 6.9; });
        //print(sequence);
    }

    // tempalte <class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
    {
        // map
    }

    {
        // unordered_map
    }

    // tempalte <class Key, class T, class Compare = less<Key>, class Allocator = allocator<pair<const Key, T>>
    {
        // set
    }

    {
        // unordered_set
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
